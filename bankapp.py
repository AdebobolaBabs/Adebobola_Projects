import random
import re


class BankAccount:
    name = None
    def __init__(self, name, password):
        self.name = name
        self.password = password
        self.account_number = str(random.randint(1000000000, 9999999999))
        self.balance = 50.0

    def send_money(self, amount):
        while amount > self.balance:
            print("Sorry, you do not have sufficient funds to complete this transaction.")
            amount = float(input("Enter the amount you want to send: "))
            user_account.send_money(amount)
        else:
            self.balance = self.balance - amount
            print("Great! Your transaction was successful.")

    def check_balance(self):
        return self.balance

    def borrow_money(self, amount):
        option = ["Emergency", "Medical", "Education", "Home Repair", "Others"]

        reason = int(input(
            "Why would you like to borrow money?\nOptions:\n1.Emergency\n2.Medical\n3.Education\n4.Home repair\n5.Others\nPlease type in a number: "))

        if reason == 5:
            custom_reason = input("Please specify your reason for borrowing: ")
            print("Our accountant will review your reason and reply in 2-5 working days.")
        else:
            print("You selected " + option[reason - 1])
            confirm = input(f"Are you sure you want to borrow ${amount}? (yes/no): ")
            if confirm == "yes" or "Yes":
                monthly_payment = amount * 0.10
                self.balance += amount
                print(
                    f"Congratulations! You have borrowed ${amount}. "
                    f"You need to pay back ${monthly_payment:.2f} every month.")
                print(f"Your balance is ${self.balance}.")
            else:
                print("Loan request canceled.")


def create_account():
    name = input("Welcome to Quezela Bank! Please enter your name: ")
    while True:
        password = input("Create a password for your account: ")
        if (
                len(password) >= 8
                and re.search(r"[a-z]", password) is not None  # At least one lowercase letter
                and re.search(r"[A-Z]", password) is not None  # At least one uppercase letter
                and re.search(r"\d", password) is not None  # At least one digit
        ):
            break
        else:
            print("Password must contain at least 8 characters, including at least one uppercase letter, "
                  "one lowercase letter, and one number.")

    account = BankAccount(name, password)
    return account


if __name__ == "__main__":
    print("Welcome to Quezela Bank App!")
    user_account = create_account()

    print("\nAccount Details:")
    print("Name:", user_account.name)
    print("Account Number:", user_account.account_number)
    print("Balance:", user_account.check_balance())

    while True:

        choice = int(input("\nDo you want to do anything else?(Select a Number)\n1.Yes\n2.No "))
        if choice == 2:
            print("Thanks for banking with Quezela!")
            break
        elif choice == 1:
            action = int(input("What would you like to do?(Select a Number)\n1.Send money\n2.Check balance\n3.Borrow money: "))
            if action == 1:
                recipient_name = input("Enter the recipient's name: ")
                amount = float(input("Enter the amount you want to send: "))
                user_account.send_money(amount)
            elif action == 2:
                print("Your current balance:", user_account.check_balance())
            elif action == 3:
                amount_to_borrow = float(input("How much money would you like to borrow? "))
                user_account.borrow_money(amount_to_borrow)
            else:
                print("Invalid choice. Please try again.")
