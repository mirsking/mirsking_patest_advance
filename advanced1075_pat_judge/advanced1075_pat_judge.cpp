#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

struct PATer{
	int ID;
	int rank;
	vector<int> scores;
	int sum;
	vector<bool> solved;
	int solved_num;
	vector<bool> perfectly_solved;
	int perfectly_solved_num;
	PATer(int K):ID(0), rank(0), sum(0), solved_num(0), perfectly_solved_num(0){
		scores = vector<int>(K, -1);
		solved = vector<bool>(K, false);
		perfectly_solved = vector<bool>(K, false);
	}
	bool operator < (const PATer& rhs) const
	{
		if (sum != rhs.sum)
			return sum < rhs.sum;
		else
		{
			if (perfectly_solved_num != rhs.perfectly_solved_num)
				return perfectly_solved_num < rhs.perfectly_solved_num;
			else
			{
				return ID>rhs.ID;
			}
		}
	}
};

int main()
{
	int N, K, M;
	cin >> N >> K >> M;
	vector<int> problems;
	problems.resize(K);
	for (int i = 0; i < K; i++)
	{
		cin >> problems[i];
	}

	vector<PATer> paters;
	unordered_map<int, int> index;
	for (int i = 0; i < M; i++)
	{
		int id, ind, score;
		cin >> id >> ind >> score;
		ind = ind - 1;
		PATer* pater;
		bool find_flag = false;
		if (index.find(id) != index.end())
		{
			pater = &paters[index[id]];
			find_flag = true;
		}
		else
		{
			index[id] = paters.size();
			pater = new PATer(K);
			find_flag = false;
		}

		pater->ID = id;
		if (score != -1)
		{
			if (score > pater->scores[ind])
			{
				pater->sum += score;
				if (pater->scores[ind] != -1)
					pater->sum -= pater->scores[ind];
				pater->scores[ind] = score;
			}
			if (pater->solved[ind] == false)
			{
				pater->solved[ind] = true;
				pater->solved_num += 1;
			}
			if (pater->scores[ind] == problems[ind] && pater->perfectly_solved[ind] == false)
			{
				pater->perfectly_solved[ind] = true;
				pater->perfectly_solved_num++;
			}
		}
		else
		{
			if (pater->scores[ind] == -1)
				pater->scores[ind] = 0;
		}
		
		if (find_flag == false)
			paters.push_back(*pater);
		
	}

	//get valid ones
	vector<PATer> valid_paters;
	for (auto& pater : paters)
	{
		if (pater.solved_num > 0)
			valid_paters.push_back(pater);
	}
	
	
	sort(valid_paters.rbegin(), valid_paters.rend());
	//update rank;
	int last_sum = -1;
	int last_rank = 1;
	int rank = 1;
	for (auto it = valid_paters.begin(); it != valid_paters.end(); it++)
	{
		if (it->sum == last_sum)
			it->rank = last_rank;
		else
		{
			last_sum = it->sum;
			last_rank = rank;
			it->rank = rank;
		}
		rank++;
	}

	for (auto& pa : valid_paters)
	{
		printf("%d %05d %d", pa.rank, pa.ID, pa.sum);
		for (auto& sc:pa.scores)
		{
			if (sc != -1)
				printf(" %d", sc);
			else
				printf(" -");
		}
		printf("\n");
	}

	return 0;
}