import collections

def all_simple_paths_graph(G, source, targets, cutoff):
    visited = collections.OrderedDict.fromkeys([source])
    # visited に現在のパスの情報を追加保存する
    # 必要がある．辞書の値に，積んである荷物量や発時刻などを保管しておく．

    stack = [iter(G[source])]
    while stack:
        children = stack[-1]  # 後続点の集合をイテレータとして得る
        # print("children=", list(children) )

        child = next(children, None)  # 後続点から1つの点を選択する．なければNone
        if child is None:  # もう調べる後続点がなければ、スタックを減らす
            stack.pop()
            visited.popitem()
        elif len(visited) < cutoff:
            if child in visited:  # すでに訪問いている点ならコンティニュー
                continue

            #  ここでvisited[-1] からchildへ移動可能かどうかのcheckを入れる。
            print(" from", list(visited)[-1], " to", child)
            # 時間枠のcheckし、実行不可能や閾値を超えた待ち時間が生じるならなcontinueなど

            if child in targets:
                # visitedに現在の点を追加したものを出力
                yield list(visited) + [child]
            visited[child] = None
            if targets - set(visited.keys()):
                # expand stack until find all targets
                stack.append(iter(G[child]))
            # 次の後続点集合をスタックに追加（深さ優先探索）
            else:
                visited.popitem()  # maybe other ways to child
        else:  # len(visited) == cutoff:
            for target in (targets & (set(children) | {child})) - set(visited.keys()):
                yield list(visited) + [target]
            # visitedに現在の点を追加したものを出力
            stack.pop()  # カットオフ値に達したら、スタックを減らす
            visited.popitem()


G = nx.complete_graph(4)
for path in all_simple_paths_graph(G, source=0, targets={3}, cutoff=len(G) - 1):
    print(path)