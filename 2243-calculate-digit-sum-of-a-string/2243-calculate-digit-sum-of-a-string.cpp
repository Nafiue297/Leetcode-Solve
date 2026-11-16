
class Solution {
public:
    string digitSum(string s, int k) {
        while(s.size() > k)
        {
            string tmp;
            int sum = 0;
            int cnt = 0;
           

            for(int i = 0; i < s.size(); i++)
            {
                cnt++;
                sum += s[i] - '0';

                if(cnt == k)
                {
                    tmp += to_string(sum);
                    cnt = 0;
                    sum = 0;
                }
            }

            if(cnt > 0)
                tmp += to_string(sum);

            s = tmp;
        }

        return s;
    }
};
