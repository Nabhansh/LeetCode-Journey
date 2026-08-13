class OrderedStream {
private:
    vector<string> stream;
    int pointer;

public:
    OrderedStream(int n) {
        stream.resize(n + 1);
        pointer = 1;
    }

    vector<string> insert(int idKey, string value) {
        stream[idKey] = value;

        vector<string> result;

        while (pointer < stream.size() &&
               !stream[pointer].empty()) {
            result.push_back(stream[pointer]);
            ++pointer;
        }

        return result;
    }
};