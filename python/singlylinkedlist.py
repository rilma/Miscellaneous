
class Node(object):

    def __init__(self, data=None, next_node=None):

        self.data = data
        self.next_node = next_node

    def get_data(self):

        return self.data

    def get_next(self):

        return self.next_node

    def set_next(self, new_next):

        self.next_node = new_next


class LinkedList(object):

    def __init__(self, head=None):

        self.head = Node(head)

    def insert(self, data):

        new_node = Node(data)
        new_node.set_next(self.head)
        self.head = new_node

    def size(self):

        curr_node = self.head        
        counter = 0
        while curr_node != None:
            curr_node = curr_node.get_next()
            counter += 1

        return counter


    def print(self):

        x = []

        if self.head == None:
            return
        else:
            curr_node = self.head
            while True:
                x.append(curr_node.data)
                if curr_node.next_node != None:
                    curr_node = curr_node.get_next()
                else:
                    print(x)
                    break
                



if __name__ == '__main__':

    # Declare value of head
    head_value = 100

    # Define a linked list
    myList = LinkedList(head_value)

    # Add values to the linked list
    for x in range(head_value, 0, -20):
        myList.insert(x)

    # Size of linked list
    print(myList.size())

    # Print values of nodes 
    myList.print()
