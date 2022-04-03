# last updated 4th april 2022
"""----------------------------------------------------------------------------------
Lab 24
Write a python program to add few customer details into the database and
retrieve the information and print in systematic manner

---------------------------------------------------------------------------------"""


import sqlite3 as db

conn = db.Connection('customer.db')
cursor = conn.cursor()
cursor.execute("create table if not exists customer(id integer primary key,name text,salary integer,address text)")


class Customer:
    def __init__(self):
        pass

    def insert_data(self, cust_id, cust_name, cust_sal, cust_address):
        if cursor.execute(f"insert into customer values({cust_id},'{cust_name}',{cust_sal},'{cust_address}')"):
            print("data inserted")
        else:
            print("data insertion failed")

    def print_data(self, cust_id=None):
        if cust_id is not None:
            query = f"select * from customer where cust_id={cust_id}"
        else:
            query = "select * from customer"
        data = cursor.execute(query)
        data = data.fetchall()
        print("id\tname\tsalary\taddress")
        for row in data:
            print(f"{row[0]}\t{row[1]}\t{row[2]}\t{row[3]}")

    def update_data(self):
        cust_id = int(input("Enter the customer Id whose data you wish to update: "))
        if cursor.execute(f"select * from customer where id={cust_id}"):
            name = input("Enter the Name: ")
            salary = int(input("Enter the salary: "))
            address = input("Enter the Address: ")
            if cursor.execute(f"update customer set name='{name}', salary={salary},address='{address}' where id={cust_id}"):
                print("Data successfully updated")
            else:
                print("Data updation failed")
        else:
            print(f"no data found for custoner id {cust_id}")

    def delete_data(self):
        cust_id = int(input("Enter the custid you wish to delete: "))
        if cursor.execute(f"delete from customer where id={cust_id}"):
            print("Data successfully deleted")
        else:
            print("Data deletion failed")


while True:
    c = Customer()
    choice = int(input("Enter the choice\n1. Insert\t2. Display\t3.Display specific\t4.update\t5.Delete\t6. Exit\nEnter your choice: "))
    if choice == 1:
        c_id = int(input("Enter the customer id: "))
        name = input("Enter the name: ")
        salary = int(input("Enter the salary: "))
        address = input("Enter the address: ")
        c.insert_data(cust_id=c_id, cust_name=name, cust_sal=salary, cust_address=address)
        # insert_data(cust_id=101, cust_name='anston', cust_sal=20000,cust_address='mangalore')
    elif choice == 2:
        c.print_data()
    elif choice == 3:
        cust_id = int(input("Enter the customer number: "))
        c.print_data()
    elif choice == 4:
        c.update_data()
    elif choice == 5:
        c.delete_data()
    elif choice == 6:
        conn.close()
        break
    else:
        print("Invalid choice.")
