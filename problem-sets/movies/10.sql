--In 10.sql, write a SQL query to list the names of all people who have directed a movie that received a rating of at least 9.0.
--Your query should output a table with a single column for the name of each person.
--If a person directed more than one movie that received a rating of at least 9.0, they should only appear in your results once.

select distinct name from people inner join directors on people.id = directors.person_id inner join ratings on directors.movie_id = ratings.movie_id where rating >= 9.0;