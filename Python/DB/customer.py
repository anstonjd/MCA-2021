# last updated 2nd april 2022
"""----------------------------------------------------------------------------------
Lab 24
Write a python program to add few customer details into the database and
retrieve the information and print in systematic manner

---------------------------------------------------------------------------------"""


import sqlite3 as db

conn = db.Connection('customer.db')
cursor = conn.cursor()
cursor.execute("create table if not exists customer(id integer primary key,name text,salary integer,address text)")


def insert_data(cust_id, cust_name, cust_sal, cust_address):
    if cursor.execute(f"insert into customer values({cust_id},'{cust_name}',{cust_sal},'{cust_address}')"):
        print("data inserted")
    else:
        print("data insertion failed")


def print_data():
    data = cursor.execute("select * from customer")
    data = data.fetchall()
    print("id\tname\tsalary\taddress")
    for row in data:
        print(f"{row[0]}\t{row[1]}\t{row[2]}\t{row[3]}")


while True:
    choice = int(input("Enter the choice\n1. Insert\t2. Display\t3. Commit Data\t4.Exit"))
    if choice == 1:
        c_id = int(input("Enter the customer id"))
        name = input("Enter the name")
        salary = int(input("Enter the salary"))
        address = input("Enter the address")
        insert_data(cust_id=c_id, cust_name=name, cust_sal=salary, cust_address=address)
        # insert_data(cust_id=101, cust_name='zaz', cust_sal=20000,cust_address='mangalore')

    elif choice == 2:
        print_data()

    elif choice == 3:
        conn.commit()

    elif choice == 4:
        break
    else:
        print("Invalid choice.")
