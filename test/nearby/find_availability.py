from cs50 import SQL

db = SQL("sqlite://amazon.db")

def find_availability(item_id):
    """Returns a list of warehouses in which an item with `item_id` is in stock"""
    db.execute("select warehouses.id, warehouses.name from warehouses inner join items on warehouse.id = items.warehouse_id where stock >= 0")