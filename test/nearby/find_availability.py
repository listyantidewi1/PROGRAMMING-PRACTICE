from cs50 import SQL

db = SQL("sqlite://amazon.db")


def find_availability(item_id):
    """Returns a list of warehouses in which an item with `item_id` is in stock"""
    warehouse = db.execute(
        "select warehouses.id from warehouses inner join items on warehouses.id = items.warehouse_id where stock >= 0 and items.id = ?", item_id)
    return warehouse

