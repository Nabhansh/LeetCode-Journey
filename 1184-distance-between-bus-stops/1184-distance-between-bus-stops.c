int distanceBetweenBusStops(int* distance, int distanceSize, int start, int destination) {
    if (start > destination) {
        int t = start;
        start = destination;
        destination = t;
    }

    int clockwise = 0;
    int total = 0;

    for (int i = 0; i < distanceSize; i++) {
        total += distance[i];
        if (i >= start && i < destination)
            clockwise += distance[i];
    }

    int anticlockwise = total - clockwise;

    return clockwise < anticlockwise ? clockwise : anticlockwise;
}