const u64 mask = std::chrono::steady_clock::now().time_since_epoch().count();
u64 shift(u64 x) {x ^= mask,  x ^= x << 13, x ^= x >> 7, x ^= x << 17, x ^= mask; return x;}

Save this one will thank me one day :)

Best bitmask hash ever for permutations of arrays