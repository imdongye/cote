imdongye@naver.com
fst : 2024-01-01
lst : 2024-12-01



## usage
update only_one var in CMakeLists.txt



## methods
* fs : DFS(stack), BFS(queue)
* dp : DP
* bt : back tracking
* sm : simulation 
* gd : greedy
* di : dijkstra
    방향 무방향 그래프에서 시작점에서부터 다른 모든 정점까지 최단거리
        음수는 안됨
        우선순위큐
    플루이드는 모든 최단거리 계산
* ms : mst
    그래프를 트리로 변환
    간선의 합이 최소
    edge는 v-1개
    1 크루스칼 => union find 그룹으로 사이클인지 확인, 간선 비용 적은순으로 연결
    2 프림 => 우선순위큐



## problem sets
* sst : samsung sw test
* boj : beakjoon



## folder name convention
methods_problemsets_number
e.g. bt_boj_15649



## Todo
* 크루스칼 union find 
* 플루이드
* 6각형 타일 회전 카운트
* 버전 정렬
