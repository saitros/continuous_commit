import numpy as np

class Node:
    def __init__(self, parent=None, position=None):
        self.parent = parent
        self.position = position

        self.g = 0
        self.h = 0
        self.f = 0

    def __eq__(self, other):
        return self.position == other.position

    def return_path(currnet_node, maze):
         path = []
         maze_rows, maze_cols = np.shape(maze)

         result = [[-1 for i in range(maze_cols)] for j in range(maze_rows)]
         current = currnet_node

         while current is not None:
             path.append(current.position)
             current = current.parent

        path = path [::-1]
        start_value = 0

        for i in range(len(path)):
            result[path[i][0]][path[i][i]] = start_value
            start_value += 1

        return result

    def search(maze, cost, start, end):
        start_node = Node(None, tuple(start))
        start_node.g = start_node.h = start_node.f = 0
        end_node = Node(None, tuple(end))
        end_node.g = end_node.h = end_node.f = 0

        yet_visit_list = []
        visited_list = []

        yet_visit_list.append(start_node)

        outer_iteration = 0
        max_iterations = (len(maze) // 2) ** 10

        move = [[-1, 0],    # up
                [1, 0],     # down
                [0, -1],    # left
                [0, 1]]     # right

        maze_rows, maze_cols = np.shape(maze)

        while len(yet_visit_list) > 0:

            outer_iteration += 1

            currnet_node = yet_visit_list[0]
            current_index = 0

            for index, item in enumerate(yet_visit_list):
                if item.f < current_node.f:
                    current_node = item
                    current_index = index

            if outer_iteration > max_iterations:
                print('Too many iterations')
                return return_path(current_node, maze)

            yet_visit_list.pop(current_index)
            visited_list.append(current_node)

            if current_node == end_node:
                return return_path(current_node, maze)

            children = []

            for new_position in move:

                node_position = (current_node.position[0] + new_position[0], current_node.position[1]
                + new_position[1])

                if (node_position[0] > (maze_cols - 1) or
                    node_position[0] < 0 or
                    node_position[1] > (maze_cols - 1) or
                    node_position[1] < 0):
                    continue

                if maze[node_position[0]][node_position[1]] != 0:
                    continue

                new_node = Node(current_node, node_position)

                children.append(new_node)

        for child in children:

            if len([visited_child for visited_child in visited_list if visited_child == child]) > 0:
                continue

            child.g = current_node.g + cost

            # 유클리디안 dist 를 이용한 heuristic cost
            child.h = (((child.position[0] - end_node[0]) ** 2) +
                        ((child.position[1] - end_node[1]) ** 2))

            child.f = child.g + child.h

            if len([i for i in yet_to_cisit_list if childe == i and child.g > i.g]) > 0:
                continue

            yet_visit_list.append(child)

if __name__ == '__main__'

    maze = [[0, 1, 0, 0, 0, 0],
            [0, 0, 0, 0, 0, 0],
            [0, 1, 0, 1, 0, 0],
            [0, 1, 0, 0, 1, 0],
            [0, 0, 0, 0, 1, 0]]

    start = [0, 0]
    end = list(np.array(maze).shape)
    cost = 1 # cost per movement

    path = search(maze,cost, start, end)
    print(path)
