//find shortest path in a graph
void dijkstra(long long start, long long goal, long long *dis, long long *prev, vector<pair<int,int> > *mat)
{
  priority_queue<pair<long long, long long> > pq;
  while(!pq.empty()) pq.pop();
  for(long long i = 0; i < MAXX; i++) dis[i] = INF, prev[i] = i;
  dis[1] = 0;
  pq.push(make_pair(0, start));
  while(pq.empty() == false)
  {
    pair<long long, long long> cur = pq.top();
    pq.pop();
    long long node = cur.second;
    if(node == goal)
      break;
    for(long long i = 0; i < mat[node].size(); i++)
    {
      if(dis[mat[node][i].first] <= dis[node]+mat[node][i].second)
        continue;
      dis[mat[node][i].first] = dis[node]+mat[node][i].second;
      prev[mat[node][i].first] = node;
      pq.push(make_pair(-1*dis[mat[node][i].first], mat[node][i].first));
    }		
  }
}
