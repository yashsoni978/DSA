<h2>355. Design Twitter</h2>

<img src="https://img.shields.io/badge/Difficulty-Medium-orange" alt="Difficulty: Medium"/>

<hr>

<p>Design a simplified version of Twitter where users can post tweets, follow or unfollow other users, and retrieve the <strong>10 most recent tweets</strong> in their news feed.</p>

<p>Implement the <code>Twitter</code> class:</p>

<ul>
  <li><code>Twitter()</code> Initializes your Twitter object.</li>
  <li><code>void postTweet(int userId, int tweetId)</code> Composes a new tweet with the given <code>tweetId</code>.</li>
  <li><code>List&lt;Integer&gt; getNewsFeed(int userId)</code> Returns the 10 most recent tweet IDs in the user's news feed. The news feed should contain tweets posted by the user and by users they follow, ordered from most recent to least recent.</li>
  <li><code>void follow(int followerId, int followeeId)</code> Makes <code>followerId</code> follow <code>followeeId</code>.</li>
  <li><code>void unfollow(int followerId, int followeeId)</code> Makes <code>followerId</code> unfollow <code>followeeId</code>.</li>
</ul>

<hr>

<p><strong>Example 1:</strong></p>

<pre>
<strong>Input:</strong>

["Twitter","postTweet","getNewsFeed",
 "follow","postTweet","getNewsFeed",
 "unfollow","getNewsFeed"]

[[],[1,5],[1],[1,2],[2,6],[1],[1,2],[1]]

<strong>Output:</strong>

[null,null,[5],null,null,[6,5],null,[5]]

<strong>Explanation:</strong>

Twitter twitter = new Twitter();

twitter.postTweet(1, 5);

twitter.getNewsFeed(1);
// returns [5]

twitter.follow(1, 2);

twitter.postTweet(2, 6);

twitter.getNewsFeed(1);
// returns [6,5]

twitter.unfollow(1, 2);

twitter.getNewsFeed(1);
// returns [5]
</pre>

<hr>

<p><strong>Constraints:</strong></p>

<ul>
  <li><code>1 ≤ userId, followerId, followeeId ≤ 500</code></li>
  <li><code>0 ≤ tweetId ≤ 10<sup>4</sup></code></li>
  <li>All <code>tweetId</code> values are unique.</li>
  <li>At most <code>3 × 10<sup>4</sup></code> calls will be made to all methods.</li>
  <li>A user cannot unfollow themselves.</li>
</ul>

<p><strong>Follow-up:</strong> Can you design the system using a <strong>Hash Map</strong> for users and follow relationships, store tweets with timestamps, and use a <strong>Max Heap (Priority Queue)</strong> to efficiently merge recent tweets from followed users, achieving <code>O((F + 10) \log F)</code> time for retrieving the news feed, where <code>F</code> is the number of followed users?</p>
