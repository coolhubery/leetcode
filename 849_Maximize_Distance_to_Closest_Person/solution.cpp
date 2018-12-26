class Solution {
public:
    int maxDistToClosest_8ms(vector<int>& seats) {

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

    int maxDistToClosest_16ms(vector<int>& seats) {

        const int len = seats.size();
        vector<int> newVec;

        // Skip the first and the last one.
        for (int i = 0; i < len; ++i) {
            if (seats[i] == 1) {
                newVec.push_back(i);
            }
        }

        int prev = 0, maxI = 0;

        for (int i = 0; i < newVec.size(); ++i) {

			// max() will increase runtime time from 12ms to 16ms.
            maxI = max(maxI, newVec[i] - prev - 1);
            prev = newVec[i];
        }

		// Eliminate max() will decrease the runtime to 12ms.
        int other = max(newVec[0], (len - newVec[newVec.size() - 1] - 1));

        if ((maxI + 1) / 2 > other) {
            return (maxI+1)/2;
        } else {
            return other;
        }
    }

	// Search the left and right of the current position.
    int maxDistToClosest_16ms(vector<int>& seats) {

        const int len = seats.size();

        int left, right, res = 0, tmpRes = 0;

        for (int i = 0; i < len; ++i) {

            if (seats[i] == 0) {

                left = right = i;

                while (--left >= 0 && seats[left] != 1) {
                }

                while (++right <= len-1 && seats[right] != 1) {
                }

                if (i == 0) {
                    res = right - i;
                    i = right;
                } else if (i == len - 1) {
                    res = max(res, i - left);
                } else {
                    res = max(res, min(i - left, right - i));
                }
            }            
        }

        return res;
    }
};
