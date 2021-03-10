class TransactionNode:
    def __init__(self, transaction_type, value):
        self.transaction_type = transaction_type
        self.value = value

    def __str__(self) -> str:
        return f"({self.transaction_type}, {self.value})"


class TransactionalStack:
    def __init__(self):
        # main container for stack
        self.stack = []
        # current container size
        self.size = 0
        # list of transaction log stacks
        self.transaction_log_stack = []
        # how many active transactions are there?
        self.active_transaction_count = 0

    def push(self, value, rolling_back=False) -> None:
        self.stack.append(value)
        self.size += 1

        """
        when not rolling back the stack and there is atleast one active transaction,
        create a new corresponding TransactionNode for the action and push it into
        the latest transaction log stack
        """
        if not rolling_back and self.active_transaction_count > 0:
            self.transaction_log_stack[-1].append(
                TransactionNode("push", value)
            )

    def __pop__(self, rolling_back=False) -> bool:
        if self.size == 0:
            return False

        value_popped = self.stack.pop()
        self.size -= 1

        """
        when not rolling back the stack and there is atleast one active transaction,
        create a new corresponding TransactionNode for the action and push it into
        the latest transaction log stack
        """
        if not rolling_back and self.active_transaction_count > 0:
            self.transaction_log_stack[-1].append(
                TransactionNode("pop", value_popped)
            )
        return True

    def pop(self, k) -> None:
        for i in range(k):
            if not self.__pop__():
                break

    def top(self, k) -> int:
        """
        stack[-(k + 1)] because of reversing index (we access backwards by using
        negative indices)
        k = 0 => index: -1
        k = 1 => index: -2
        k = 2 => index: -3
        ...
        """
        return self.stack[-(k + 1)] if k < self.size else 0

    def begin(self) -> None:
        """
        begin a new transaction is just add a new transaction log stack
        """
        self.transaction_log_stack.append([])
        self.active_transaction_count += 1

    def rollback(self) -> bool:
        if self.active_transaction_count == 0:
            return False

        """
        rollback a transaction is reading the latest transaction log stack and do
        the opposite actions correspoding to the logged actions in reverse order
        """
        while len(self.transaction_log_stack[-1]) > 0:
            action = self.transaction_log_stack[-1].pop()

            if action.transaction_type == "push":
                self.__pop__(rolling_back=True)
            elif action.transaction_type == "pop":
                self.push(value=action.value, rolling_back=True)

        self.transaction_log_stack.pop()
        self.active_transaction_count -= 1
        return True

    def commit(self) -> bool:
        if self.active_transaction_count == 0:
            return False

        """
        if there are multiple active transactions, when we commit a transaction,
        we should transfer all the log stack of the committed layer to the previous
        layer
        this is for the need of rolling back previous transaction(s)
        """
        if self.active_transaction_count > 1:
            for transaction_node in self.transaction_log_stack[-1]:
                self.transaction_log_stack[-2].append(transaction_node)

        """
        when commit, we just need to pop the latest transaction log stack because
        all the changes are already applied to the main container
        """
        self.transaction_log_stack.pop()
        self.active_transaction_count -= 1
        return True


def main():
    q = int(input())

    stack = TransactionalStack()

    # parsing inputs and do the corresponding actions
    for i in range(q):
        line = input().split()
        if len(line) == 2:
            action, value = line
            value = int(value)
            if action == "push":
                stack.push(value)
            elif action == "pop":
                stack.pop(value)
            elif action == "top":
                print(stack.top(value))
            else:
                # for validating input purposes only
                raise ValueError(
                    "Action `{}` not defined in statement".format(action)
                )
        elif len(line) == 1:
            action = line[0]
            if action == "begin":
                stack.begin()
            elif action == "commit":
                print("true" if stack.commit() else "false")
            elif action == "rollback":
                print("true" if stack.rollback() else "false")
            else:
                # for validating input purposes only
                raise ValueError(
                    "Action `{}` not defined in statement".format(action)
                )


if __name__ == "__main__":
    main()
