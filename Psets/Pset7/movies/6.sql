SELECT AVG(ratings.rating)
from ratings
INNER JOIN movies
ON ratings.movie_id = movies.id
WHERE
(
    movies.year = '2012'
);
