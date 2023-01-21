--in 13.sql, write a SQL query to list the names of all people who starred in a movie in which Kevin Bacon also starred.
--Your query should output a table with a single column for the name of each person.
--There may be multiple people named Kevin Bacon in the database. Be sure to only select the Kevin Bacon born in 1958.
--Kevin Bacon himself should not be included in the resulting list.l
select name from people inner join stars
on people.id = stars.person_id
inner join movies
on stars.movie_id = movies.id
where movies.id IN
    (select movies.id from movies inner join stars
    on movies.id = stars.movie_id
    inner join people
    on stars.person_id = people.id
    where name = "Kevin Bacon" and birth = 1958)
and name != "Kevin Bacon";