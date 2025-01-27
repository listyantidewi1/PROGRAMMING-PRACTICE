--In 11.sql, write a SQL query to list the titles of the five highest rated movies (in order) that Chadwick Boseman starred in, starting with the highest rated.
--Your query should output a table with a single column for the title of each movie.
--You may assume that there is only one person in the database with the name Chadwick Boseman.

select title from movies inner join stars on movies.id = stars.movie_id inner join ratings on stars.movie_id = ratings.movie_id inner join people on stars.person_id = people.id where name = 'Chadwick Boseman' order by rating desc limit 5;