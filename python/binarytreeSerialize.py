
class BinaryTree(object):

    def __init__(self, value):
        self.value = value
        self.left, self.right = None, None

    def SetLeft(self, node):
        self.left = node

    def SetRight(self, node):
        self.right = node

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

    def Deserialize(self, data):

        def DeserializeHelper():
            val = next(vals)
            if val == 'None':
                return None
            node = BinaryTree(int(val))
            node.left = DeserializeHelper()
            node.right = DeserializeHelper()
            return node

        vals = iter(data.split())

        return DeserializeHelper()


if __name__ == '__main__':

    """
    
    Binary Tree example
            1
        2       3
            4
        
    Serialize:
        1 2 None 4 3 None None
        
    """
    
    root = BinaryTree(1)

    left = BinaryTree(2)
    left.SetRight(BinaryTree(4))

    right = BinaryTree(3)

    root.SetLeft(left)
    root.SetRight(right)

    data = root.Serialize(root)    
    tree = root.Deserialize(data)
    
