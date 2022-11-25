SELECT COUNT (ratings.rating)
FROM ratings
INNER JOIN movies
ON ratings.movie_id = movies.id
WHERE
(
    ratings.rating = '10.0'
);