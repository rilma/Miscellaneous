
class BinaryTree(object):

    def __init__(self, value):
        self.value = value
        self.left, self.right = None, None
        self.parent = None

    def SetLeft(self, node):
        self.left = node
        self.left.parent = self

    def SetRight(self, node):
        self.right = node
        self.right.parent = self

    def Serialize(self, root):

        def SerializeHelper(node):
            if not node:
                result.append('None')
            else:
                result.append(str(node.value))
                SerializeHelper(node.left)
                SerializeHelper(node.right)

        result = []
        SerializeHelper(root)
        
        return ' '.join(result)


if __name__ == '__main__':

    root = BinaryTree(1)

    left = BinaryTree(2)
    left.SetRight(BinaryTree(4))

    right = BinaryTree(3)

    root.SetLeft(left)
    root.SetRight(right)

    print(root.Serialize(root))