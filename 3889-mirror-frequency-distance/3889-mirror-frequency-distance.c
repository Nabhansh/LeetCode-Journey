int mirrorFrequency(const char * const str){
	int chToCnt[128];
	memset(&chToCnt, 0, sizeof (chToCnt));
	for (int i = 0; str[i] != '\0'; i += 1){
		chToCnt[str[i]] += 1;
	}

	int sum = 0;

	for (char left = 'a', right = 'z'; left < right; left += 1, right -= 1){
		sum += abs(chToCnt[left] - chToCnt[right]);
	}
	for (char left = '0', right = '9'; left < right; left += 1, right -= 1){
		sum += abs(chToCnt[left] - chToCnt[right]);
	}

	return sum;
}