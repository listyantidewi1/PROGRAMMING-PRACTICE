CREATE TABLE warehouses (
    id int(5) NOT NULL AUTO_INCREMENT,
    name varchar(255) NOT NULL,
    latitude varchar(255) NOT NULL,
    longitude varchar(255) NOT NULL,
    PRIMARY KEY (id)
);

CREATE TABLE items (
    id int NOT NULL,
    warehouse_id int(5) NOT NULL,
    name varchar(255) NOT NULL,
    stock int(5) NOT NULL,
    PRIMARY KEY (id),
    FOREIGN KEY (warehouse_id) REFERENCES warehouse (id)
)