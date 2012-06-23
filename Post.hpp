#ifndef POST_HPP
#define POST_HPP

class Post{
	public:
		string postID;
		string fromID;
		string content;
		string createdTime;
		string nLike;
		string place;
		Post(string in_postID, string in_fromID, string in_content, string in_createdTime, string in_nLike, string in_place):
			postID(in_postID), fromID(in_fromID), content(in_content), createdTime(in_createdTime), nLike(in_nLike), place(in_place){}

};

#endif //POST_HPP
