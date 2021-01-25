"""
LINE CODE WOW - Round 3

Design an algorithm for recommending Articles on a social media for a specific user X with different priorities:

- First priority:  Alternate between an article from X's following fanpage(s) posted within 7 days and sorted in descending order of views and creation time
                   and an article from X's following friend(s) within 7 days sorted in descending order of views and creation time. Prioritize a fanpage
                   article to appeared first on the timeline if it is possible.
- Second priority: Alternate between a public article with over 1000 views, posted within 7 days and sorted in descending order of views and creation time and
                   an article from X's following user(s) with over 100 views, posted within 7 days and sorted in descending order of views and creation time.
                   Prioritize a public article to appeared first on the timeline if it is possible.
- Third priority:  Show all the articles from X's friend(s), sorted in descending order of views and creation time.

Note:
- Two users are friends with each other does not mean that they are following each other.
- All articles must appear only once across all 3 priorities

Input:

There are N given informations. There are 5 kind of informations:
- friends <user1> <user2> : <user1> and <user2> are friends
- follow-user <user1> <user2> : <user1> follows <user2>
- follow-fanpage <user> <fanpage> : <user1> follows fanpage <fanpage>
- fanpage-article <article> <fanpage> <creation time> <views> : a fanpage article created by fanpage <fanpage> at <creation time> with a view count of <views>,
                                                                all fanpage articles are public
- user-article <article> <user> <creation time> <views> <audience> : user <user> created an article at <creation time> with a view count of <views> and the
                                                                     audience setting is sets to "restricted" or "public".

For all articles: a restricted article can only be seen by the user's friend(s), and a public article can be seen by everyone

Output:

With each priority, output a single line of recommended article(s), all of which must match all the criteria provided in the above descriptions, including the
order of appearance. The first, second, and third line is the list of recommended article(s) for the first, second, and third priority, respectively.

Example:

Input

21
friends 1 2
friends 2 4
friends 1 3
follow-user 1 5
follow-user 1 4
follow-user 1 2
follow-user 4 5
follow-fanpage 1 2
follow-fanpage 3 5
follow-fanpage 1 1
follow-fanpage 2 3
fanpage-article 1 1 2020-11-30@06:30:30 10000
fanpage-article 2 5 2020-10-31@06:30:30 100000
fanpage-article 3 3 2020-12-07@06:30:30 10000
fanpage-article 4 5 2020-12-07@06:30:31 10001
fanpage-article 5 2 2020-12-07@06:30:32 500000
user-article 6 2 2020-12-07@06:30:40 200 restricted
user-article 7 5 2020-11-30@06:30:29 400 public
user-article 8 4 2020-12-07@06:31:30 500 restricted
user-article 9 2 2020-12-07@07:30:30 50 public
user-article 10 3 2020-12-07@06:31:31 101 restricted
1 2020-12-08@06:30:30

Output:

5 6 9
4 3
10

"""

from datetime import datetime, timedelta

datetime_format = "%Y-%m-%d@%H:%M:%S"

"""
This could be designed wayyyyyy better
But I'm not capable of that, though :)

"""

class Fanpage:
    def __init__(self, id: int) -> None:
        self.__id = id
        self.__articles = set()

    # for debugging purposes
    def __str__(self) -> str:
        return f"fanpge {self.__id}\n    wrote {self.__articles}"

    def add_article(self, id: int) -> None:
        self.__articles.add(id)

    def get_articles(self) -> set:
        return self.__articles

class User:
    def __init__(self, id: int) -> None:
        self.__id = id
        self.__friends = set()
        self.__following_users = set()
        self.__following_fanpages = set()
        self.__articles = set()

    # for debugging purposes
    def __str__(self) -> str:
        return f"user {self.__id}:\n    friend with {self.__friends}\n    users following {self.__following_users}\n    fanapges following {self.__following_fanpages}\n    wrote {self.__articles}"

    def is_follow_user(self, id: int) -> bool:
        return id in self.__following_users

    def is_friend_with(self, id: int) -> bool:
        return id in self.__friends

    def is_follow_fanpage(self, id: int) -> bool:
        return id in self.__following_fanpages

    def follows_user(self, id: int) -> None:
        self.__following_users.add(id)

    def follows_fanpage(self, id: int) -> None:
        self.__following_fanpages.add(id)

    def make_friend_with(self, id: int) -> None:
        self.__friends.add(id)

    def add_article(self, id: int) -> None:
        self.__articles.add(id)

    def get_following_fanpages(self) -> set:
        return self.__following_fanpages

    def get_friends(self) -> set:
        return self.__friends

    def get_following_users(self) -> set:
        return self.__following_users

    def get_articles(self) -> set:
        return self.__articles

class Article:
    def __init__(self, id: int, uploader_id: int, type: str, timestamp: datetime, views: int, audience = "public") -> None:
        self.__id = id
        self.__uploader_id = uploader_id
        self.__type = type
        self.__timestamp = timestamp
        self.__views = views
        self.__audience = audience

    # less-than operator for comparing two Article objects
    def __lt__(self, rhs) -> bool:
        return (self.__views, self.__timestamp) < (rhs.__views, rhs.__timestamp)

    # for debugging purposes
    def __str__(self) -> str:
        return f"article {self.__id}:\n    uploaded by {self.__type} {self.__uploader_id}\n    timestamp {self.__timestamp}\n    views {self.__views}\n    audience {self.__audience}"

    def get_views(self) -> int:
        return self.__views

    def get_id(self) -> int:
        return self.__id

    def is_within_seven_days_until(self, timestamp: datetime) -> bool:
        delta = timestamp - self.__timestamp
        return 0 <= delta.total_seconds() <= timedelta(days = 7).total_seconds()

    def is_public(self) -> bool:
        return self.__audience == "public"

    # check whether a given user be able to see this Article on their timeline
    def is_viewable_with_user(self, user: User) -> bool:
        # if the audience of this Article is restricted and the user is not friend with the uploader, than they can not see this Article
        # otherwise, yes, they can
        if self.__audience == "restricted" and not user.is_friend_with(self.__uploader_id):
            return False
        return True

    def is_posted_before(self, timestamp: datetime) -> bool:
        return self.__timestamp <= timestamp

"""
input parsing helper functions

"""
def create_user(user: int, users: dict[int, User]) -> None:
    if user not in users:
        users[user] = User(user)

def create_fanpage(fanpage: int, fanpages: dict[int, Fanpage]) -> None:
    if fanpage not in fanpages:
        fanpages[fanpage] = Fanpage(fanpage)

def make_friend(user1: int, user2: int, users: dict[int, User]) -> None:
    create_user(user1, users)
    create_user(user2, users)

    users[user1].make_friend_with(user2)
    users[user2].make_friend_with(user1)

def make_follow_user(follower: int, follows: int, users: dict[int, User]) -> None:
    create_user(follower, users)
    create_user(follows, users)

    users[follower].follows_user(follows)

def make_follow_fanpage(follower: int, follows: int, users: dict[int, User], fanpages: dict[int, Fanpage]) -> None:
    create_user(follower, users)
    create_fanpage(follows, fanpages)

    users[follower].follows_fanpage(follows)

def make_fanpage_article(article_id: int, fanpage: int, creation_time: datetime, views: int, fanpages: dict[int, Fanpage], articles: dict[int, Article]) -> None:
    create_fanpage(fanpage, fanpages)

    article = Article(article_id, fanpage, "fanpage", creation_time, views)
    articles[article_id] = article

    fanpages[fanpage].add_article(article_id)

def make_user_article(article_id: int, user: int, creation_time: datetime, views: int, audience: str, users: dict[int, User], articles: dict[int, Article]) -> None:
    create_user(user, users)

    article = Article(article_id, user, "user", creation_time, views, audience)
    articles[article_id] = article

    users[user].add_article(article_id)

"""
main processing functions for priority levels

"""
def make_first_priority(user: User, timestamp: datetime, seen: set[int], users: dict[int, User], articles: dict[int, Article], fanpages: dict[int, Fanpage]) -> list:
    # articles from following fanpages
    fanpage_articles = []
    for fanpage in user.get_following_fanpages():
        for article_id in fanpages[fanpage].get_articles():
            if articles[article_id].is_within_seven_days_until(timestamp):
                fanpage_articles.append(article_id)
                seen.add(article_id)

    fanpage_articles = sorted(fanpage_articles, key = lambda k: articles[k])

    # articles from following friends
    user_articles = []
    for user_id in (user.get_following_users() & user.get_friends()):
        for article_id in users[user_id].get_articles():
            if articles[article_id].is_within_seven_days_until(timestamp):
                user_articles.append(article_id)
                seen.add(article_id)

    user_articles = sorted(user_articles, key = lambda k: articles[k])

    # merge and alternating between fanpage articles and user articles
    show_articles = []
    while len(fanpage_articles) != 0 and len(user_articles) != 0:
        if len(show_articles) % 2 == 0:
            show_articles.append(fanpage_articles.pop())
        else:
            show_articles.append(user_articles.pop())

    show_articles += fanpage_articles[::-1]
    show_articles += user_articles[::-1]

    return show_articles

def make_second_priority(user: User, timestamp: datetime, seen: set[int], users: dict[int, User], articles: dict[int, Article]) -> list:
    #  public articles
    public_articles = []
    for article in articles.values():
        if article.is_public() and article.get_views() > 1000 and article.is_within_seven_days_until(timestamp) and article.get_id() not in seen:
            public_articles.append(article.get_id())
            seen.add(article.get_id())

    public_articles = sorted(public_articles, key = lambda k: articles[k])

    # articles from following users (need not to be friend)
    user_articles = []
    for user_id in user.get_following_users():
        for article_id in users[user_id].get_articles():
            if articles[article_id].get_views() > 100 and articles[article_id].is_within_seven_days_until(timestamp) and articles[article_id].is_viewable_with_user(user) and article_id not in seen:
                user_articles.append(article_id)
                seen.add(article_id)

    user_articles = sorted(user_articles, key = lambda k: articles[k])

    # merge and alternating between fanpage articles and user articles
    show_articles = []
    while len(public_articles) != 0 and len(user_articles) != 0:
        if len(show_articles) % 2 == 0:
            show_articles.append(public_articles.pop())
        else:
            show_articles.append(user_articles.pop())

    show_articles += public_articles[::-1]
    show_articles += user_articles[::-1]

    return show_articles

def make_third_priority(user: User, timestamp: datetime, seen: set[int], users: dict[int, User], articles: dict[int, Article]) -> list:
    show_articles = []

    # articles from friends
    for user_id in user.get_friends():
        for article_id in users[user_id].get_articles():
            if articles[article_id].is_posted_before(timestamp) and article_id not in seen:
                show_articles.append(article_id)
                seen.add(article_id)

    show_articles = sorted(show_articles, key = lambda k: articles[k], reverse = True)

    return show_articles

"""
main function

"""
def main() -> None:
    users = dict()
    articles = dict()
    fanpages = dict()

    n = int(input())
    for i in range(n):
        command = input().split()
        type, args = command[0], command[1:]

        # try to parse all arguments to int type for ease of use
        for j in range(len(args)):
            try:
                args[j] = int(args[j])
            except Exception:
                pass

        if type == "friends":
            assert args[0] != args[1]
            make_friend(args[0], args[1], users)
        elif type == "follow-user":
            assert args[0] != args[1]
            make_follow_user(args[0], args[1], users)
        elif type == "follow-fanpage":
            make_follow_fanpage(args[0], args[1], users, fanpages)
        elif type == "fanpage-article":
            article_id, fanpage, creation_time, views = args
            creation_time = datetime.strptime(creation_time, datetime_format)
            make_fanpage_article(article_id, fanpage, creation_time, views, fanpages, articles)
        elif type == "user-article":
            article_id, user, creation_time, views, audience = args
            creation_time = datetime.strptime(creation_time, datetime_format)
            make_user_article(article_id, user, creation_time, views, audience, users, articles)
        else:
            # input checking
            raise TypeError(f"Action `{type}` not defined in the problem statement")

    user_id, timestamp = input().split()
    user = users[int(user_id)]
    timestamp = datetime.strptime(timestamp, datetime_format)

    seen = set()
    print(*make_first_priority(user, timestamp, seen, users, articles, fanpages))
    print(*make_second_priority(user, timestamp, seen, users, articles))
    print(*make_third_priority(user, timestamp, seen, users, articles))

if __name__ == "__main__":
    main()
