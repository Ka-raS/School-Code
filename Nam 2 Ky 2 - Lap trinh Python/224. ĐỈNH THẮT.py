from typing import List

def count_articulation_point(adj_list: List[List[int]], vertex_count: int, begin_vertex: int, end_vertex: int) -> int:
    def dfs(begin: int, end: int) -> None:
        if begin == end:
            for vertex in VERTICES:
                if not visited[vertex]:
                    is_articulation[vertex] = False
            return

        for next in adj_list[begin]:
            if not visited[next]:
                visited[next] = True
                dfs(next, end)
                visited[next] = False

    VERTICES = range(1, vertex_count + 1)
    is_articulation = [True] * (vertex_count + 1)
    visited = [False] * (vertex_count + 1)
    visited[begin_vertex] = True
    dfs(begin_vertex, end_vertex)
    return sum(is_articulation) - 3 # [0] + [begin_vertex] + [end_vertex]

def run_test() -> None:
    vertex_count, edge_count, begin_vertex, end_vertex = map(int, input().split())
    adj_list: List[List[int]] = [[] for _ in range(vertex_count + 1)]
    for edge in range(edge_count):
        begin, end = map(int, input().split())
        adj_list[begin].append(end)
    print(count_articulation_point(adj_list, vertex_count, begin_vertex, end_vertex))

def main() -> None:
    tests = int(input())
    for test in range(tests):
        run_test()

if __name__ == '__main__':
    main()