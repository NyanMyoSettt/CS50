-- list the names of all people who starred in Toy Story
SELECT name from people JOIN stars on people.id = stars.person_id JOIN movies on movies.id = stars.movie_id WHERE movies.title = 'Toy Story';