#include <Geode/Geode.hpp>
#include <Geode/modify/InfoLayer.hpp>

using namespace geode::prelude;

class $modify(InfoLayer) {
	void onCopyLevelID(CCObject*) {
		/*
			Get the name of the author and the level name then string them together
			seperating them with " - " and append it with "(Geometry Dash)" lastly,
			store the result in a variable called "ytVideoTitle" for later use
		*/
		std::string ytVideoTitle = fmt::format("{} - {} (Geometry Dash)", this->m_level->m_creatorName, this->m_level->m_levelName);
		
		/* 
			Get the length of the "ytVideoTitle" variable and use the returned value to create
			a string of "=" symbols which is the same length as the "ytVideoTitle" variable
		*/
		std::string ytVideoDivider = std::string(ytVideoTitle.length(), '=');
		
		// Get the ID of the level and store it in a variabled called "ytVideoDescLevelID" for later use
		std::string ytVideoDescLevelID = std::to_string(this->m_level->m_levelID.value());
		
		// Prepare and copy the formatted data above to the clipboard for easy pasting wherever the user wants
		clipboard::write(fmt::format("{}\n{}\nLevel ID: {}\n", ytVideoTitle, ytVideoDivider, ytVideoDescLevelID));

		// Notify the player to let them know that all the level information has been copied to their clipboard
		Notification::create(("Level info copied to clipboard!"), CCSprite::create("Copy.png"_spr), 3)->show();
	}
};
