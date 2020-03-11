import matplotlib.pyplot as plt
import matplotlib.patheffects as pe
import networkx as nx
import sys
import re

colors = ['#b900ee', '#35ee00', '#4200ee', '#ee4200', '#ee4200', '#acee00']


def color(k):
    return colors[k % len(colors)]



fname = sys.argv[1]

with open(fname, 'r', encoding="utf-8") as file:
    data = file.read()
    ants = re.findall(r'^\d+', data)
    start = re.findall(r'##start\n\w+ ', data)[0][8:-1]
    end = re.findall(r'##end\n\w+ ', data)[0][6:-1]
    nds = re.findall(r'\w+ \d+ \d+', data)
    rowedges = re.findall(r'\w+-\w+', data)
    edges = []
    for i in rowedges:
        if i[0] != 'L':
            edges.append(tuple(i.split('-')))
    ways = re.findall(r'L\d+-\w+', data)
    pash = [start] * int(ants[0])
    for way in ways:
        pash[int(way.split('-')[0][1:]) - 1] += ' ' + way.split('-')[1]
    pash = set(pash)
G = nx.Graph()
nodes = {node.split()[0]: (int(node.split()[1]), int(node.split()[2])) for node in nds}
for node in nodes.items():
    G.add_node(node[0], pos=(int(node[1][0]), int(node[1][1])))
G.add_edges_from(edges)
pos = nx.get_node_attributes(G, 'pos')
# print(G.edges)
egde_list = []
used_nodes = set()
used_nodes.add(start)
for p in pash:
    node = p.split()
    temp = []
    for i in range(len(node) - 1):
        temp.append((node[i], node[i + 1]))
        used_nodes.add(node[i + 1])
    egde_list.append(temp)
# used_nodes = list(used_nodes)
start_and_end = (start, end)
# print('edge list ', egde_list)
# print('used_nodes ', used_nodes)
options = {
    'node_color': '#251103',
    'edge_color': '#4b1b06',
    'node_size': 10,
    'width': 1,
    'alpha': 0.6,
}
# G = nx.petersen_graph()
fig = plt.figure(figsize=(12, 8))
fig.add_subplot(1, 1, 1)

fig.canvas.set_window_title('Lem-in visualisation')

# plt.subplot(111)
pos = nx.spring_layout(G)
# nx.draw(G, with_labels=True, font_weight='normal', font_size=8, pos=pos, **options)
nx.draw(G, pos=pos, **options)

# pos = nx.random_layout(G)
count = 0
for e_list in egde_list:
    nx.draw_networkx_edges(G, pos, edgelist=e_list, edge_color=color(count), width=3)
    count += 1
nx.draw_networkx_nodes(G, pos, nodelist=used_nodes, node_color='#003822', node_size=20)
nx.draw_networkx_nodes(G, pos, nodelist=start_and_end, node_color='#2f0292', node_size=100)

# nx.draw_shell(G, nlist=[range(5, 10), range(5)], with_labels=True, font_weight='bold')
# options = {
#               'node_color': 'black',
#               'node_size': 100,
#               'width': 3,
# }
# nx.draw_circular(G)
fig.set_facecolor('#525252')
plt.show()
