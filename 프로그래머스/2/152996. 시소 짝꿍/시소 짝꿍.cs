using System;

    public class Solution
    {
        public long solution(int[] weights)
        {
            int[] intArray = new int[4001];
            long answer = 0;

            int count = 0; // 같은 몸무게를 가진 사람의 수
            int tempNum = 0; // 이전 사람의 몸무게

            // 1. 같은 몸무게를 가진 사람의 수를 체크하기 위한 정렬
            Array.Sort(weights);

            foreach (int weight in weights)
            {
                // 2. intArray에 2N, 3N, 4N 넣기
                intArray[weight * 2]++;
                intArray[weight * 3]++;
                intArray[weight * 4]++;

                // 3. 같은 몸무게를 가진 사람이 있는지 체크하고 예외처리
                if (tempNum == weight)
                {
                    count++;
                    answer -= count * 2; // 예외처리
                }
                else
                {
                    tempNum = weight;
                    count = 0;
                }
            }

            // 4. 균형을 이루는 사람 체크
            foreach (int num in intArray)
                if (num > 1)
                    answer += Function(num);

            return answer;
        }

        // 짝 짓는 경우의 수 구하는 함수
        public long Function(int num)
        {
            long total = 0;
            for (int i = 1; i < num; i++)
                total += i;

            return total;
        }
    }