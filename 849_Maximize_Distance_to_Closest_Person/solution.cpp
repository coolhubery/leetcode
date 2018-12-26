class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {

		// If expands the following delcaration and defnition, the total
		// runtime of the program will rise from 8ms to 12ms.
        bool firstExists, lastExists;
        int firstLength, lastLength, start, length, tmpStart, tmpLength;
        const int size = seats.size();

        firstLength = lastLength = length = tmpLength = 0;
        start = tmpStart = -1;

        firstExists = seats[0] == 0 ? true : false;
        lastExists = seats[size-1] == 0 ? true : false;


        for (int i = 0; i < size; ++i) {

            if (seats[i] == 0) {

                if (tmpStart == -1) {
                    tmpStart = i;
                }

                ++tmpLength;

            } else {

                if (start == -1) {
                    start = tmpStart;
                    length = tmpLength;

                    if (firstExists) {
                        firstLength = length;
                    }
                } else {

                    if (tmpLength > length) {
                        start = tmpStart;
                        length = tmpLength;
                    }
                }

                tmpStart = -1;
                tmpLength = 0;
            }

        }

        if (lastExists && (tmpStart + tmpLength) == size) {
            lastLength = tmpLength;
        }

        // Return result
        if (!firstExists && !lastExists) {
            return (length + 1) / 2;
        } else if (start + length == size) { // Only last exists
            return length;
        } else {
            int large = (firstLength > lastLength ? firstLength : lastLength);

            if ((length + 1) / 2 > large) {
                return (length + 1) / 2;
            } else {
                return large;
            }
        }
    }
};
