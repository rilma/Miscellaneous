
""" Simple Binary Tree implementation """


from random import randint


class TreeNode(object):

    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

    def getData(self):
        return self.data

    def setData(self, data):
        self.data = data

    def getLeft(self):
        return self.left

    def setLeft(self, left):
        self.left = left

    def getRight(self):
        return self.right

    def setRight(self, right):
        self.right = right


class Tree(object):

    def __init__(self):
        self.root = None

    def insertNode(self, value):
        if self.root == None:
            self.root = TreeNode(value)
        else:
            self.insertNodeHelper(self.root, value)

    def insertNodeHelper(self, node, value):
        if value < node.getData():
            if node.getLeft() is None:
                node.setLeft(TreeNode(value))
            else:
                self.insertNodeHelper(node.getLeft(), value)
        elif value > node.getData():
            if node.getRight() is None:
                node.setRight(TreeNode(value))
            else:
                self.insertNodeHelper(node.getRight(), value)
        else:
            print('{:d} duplicate'.format(value))


    def preOrderTraversal(self):

        self.preOrderHelper(self.root)
    

    def preOrderHelper(self, node):
        if node != None:
            print(node.getData(), end=' ')
            self.preOrderHelper(node.getLeft())
            self.preOrderHelper(node.getRight())


    def inOrderTraversal(self):

        self.inOrderHelper(self.root)


    def inOrderHelper(self, node):

        if node != None:
            self.inOrderHelper(node.getLeft())
            print(node.getData(), end=' ')
            self.inOrderHelper(node.getRight())


    def postOrderTraversal(self):

        self.postOrderHelper(self.root)


    def postOrderHelper(self, node):
        if node != None:
            self.postOrderHelper(node.getLeft())
            self.postOrderHelper(node.getRight())
            print(node.getData(), end=' ')



if __name__ == '__main__':

    tree = Tree()

    print('Random generated data:')
    N = 10
    data = []
    for _ in range(N):
        tmp = randint(1, 100)
        print(tmp, end=' ')
        tree.insertNode(tmp)

    print('\nPreorder Traversal')
    tree.preOrderTraversal()
    print('\nInorder Traversal')
    tree.inOrderTraversal()
    print('\nPostorder Traversal')
    tree.postOrderTraversal()
