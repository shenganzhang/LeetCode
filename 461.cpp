int hammingDistance(int x, int y) {
    int cnt = 0;
    while (x && y) {
        if (!(x % 2) && (y % 2)) ++cnt;
        if ((x % 2) && !(y % 2)) ++cnt;
        x = x >> 1;
        y = y >> 1;
    }
    while (x) {
        if (x % 2) ++cnt;
        x = x >> 1;
    }
    while (y) {
        if (y % 2) ++cnt;
        y = y >> 1;
    }
    return cnt;
}