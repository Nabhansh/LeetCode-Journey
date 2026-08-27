int countKthRoots(int l, int r, int k) {
    int low = (int)ceil(pow(l,1.0 / k)),high = (int)ceil(pow(r,1.0 / k));
    return pow(high,k) > r ? high - low : high - low + 1;
}