--In 8.sql, write a SQL query to list the names of all people who starred in Toy Story.
--Your query should output a table with a single column for the name of each person.
--You may assume that there is only one movie in the database with the title Toy Story.

select name from movies inner join stars on movies.id = stars.movie_id inner join people on stars.person_id = people.id where title like '%Toy Story%';