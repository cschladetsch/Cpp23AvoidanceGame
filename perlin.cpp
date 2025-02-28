#include "perlin.h"
#include <cmath>
#include <vector>
#include <random>
#include <algorithm>

std::vector<int> p;

// Initialize permutation table
struct PerlinInit {
    PerlinInit() {
        p.resize(512);
        for (int i = 0; i < 256; ++i) {
            p[i] = i;
        }
        std::random_device rd;
        std::mt19937 g(rd());
        std::shuffle(p.begin(), p.begin() + 256, g);
        for (int i = 0; i < 256; ++i) {
            p[i + 256] = p[i];
        }
    }
};

PerlinInit perlin_init;

float fade(float t) { return t * t * t * (t * (t * 6 - 15) + 10); }
float lerp(float t, float a, float b) { return a + t * (b - a); }
float grad(int hash, float x, float y) {
    int h = hash & 15;
    float u = h < 8 ? x : y;
    float v = h < 4 ? y : h == 12 || h == 14 ? x : 0;
    return ((h & 1) == 0 ? u : -u) + ((h & 2) == 0 ? v : -v);
}

float perlin2d(float x, float y) {
    int X = (int)floor(x) & 255, Y = (int)floor(y) & 255;
    x -= floor(x);
    y -= floor(y);
    float u = fade(x), v = fade(y);
    int A = p[X] + Y, B = p[X + 1] + Y, AA = p[A], AB = p[A + 1], BA = p[B], BB = p[B + 1];
    return lerp(v, lerp(u, grad(p[AA], x, y), grad(p[BA], x - 1, y)),
                    lerp(u, grad(p[AB], x, y - 1), grad(p[BB], x - 1, y - 1)));
}
