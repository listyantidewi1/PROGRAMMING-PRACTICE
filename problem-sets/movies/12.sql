--In 12.sql, write a SQL query to list the titles of all movies in which both Johnny Depp and Helena Bonham Carter starred.
--Your query should output a table with a single column for the title of each movie.
--You may assume that there is only one person in the database with the name Johnny Depp.
--You may assume that there is only one person in the database with the name Helena Bonham Carter.

select title from movies inner join stars on movies.id = stars.movie_id inner join people on stars.person_id = people.id where name = 'Johnny Depp' or name = 'Helena Bonham Carter' 