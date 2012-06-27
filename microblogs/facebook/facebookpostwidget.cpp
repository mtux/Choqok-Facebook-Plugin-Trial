/*
    This file is part of Choqok, the KDE micro-blogging client

    Copyright (C) 2011-2012 Pankaj Bhambhani <pankajb64@gmail.com>

    This program is free software; you can redistribute it and/or
    modify it under the terms of the GNU General Public License as
    published by the Free Software Foundation; either version 2 of
    the License or (at your option) version 3 or any later version
    accepted by the membership of KDE e.V. (or its successor approved
    by the membership of KDE e.V.), which shall act as a proxy
    defined in Section 14 of version 3 of the license.


    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, see http://www.gnu.org/licenses/
*/

#include "facebookpostwidget.h"

FacebookPostWidget::FacebookPostWidget(Choqok::Account* account, Choqok::Post* post, QWidget* parent): PostWidget(account, post, parent)
{

}

QString FacebookPostWidget::generateSign ()
{
    QString ss = "";
 
    
    ss = "<i><a href='"+ currentAccount()->microblog()->profileUrl( currentAccount(), currentPost()->author.userId ) 
		 +      +"' title=\"" +
    currentPost()->author.realName + "\">" ;
		
		 if (currentPost()->author.realName.isEmpty())
			ss += "Anonymous";
		else
			ss += currentPost()->author.realName;
		 	ss += "</a> - </i>";

    QStringList list = currentPost()->postId.split("_");
    
    ss += "<a href=\"http://www.facebook.com/" + list[0] + "/posts/" + list[1]
	 
	 + "\" title=\""
	 + currentPost().creationDateTime.toString(Qt::DefaultLocaleLongDate) + "\">%1</a>";

    if( !currentPost().source.isNull() && !currentPost().replyToUserId.isEmpty())
        ss += " - <a href=\"http://www.facebook.com/apps/application.php?id=" + currentPost().replyToUserId + "\">" + currentPost().source + "</a>";
    else
	ss += " - web";	

    ss += " <a href='"
	 + currentAccount()->microblog()->postUrl(currentAccount(), currentPost().author.userName, currentPost().postId)
 	 + "'>"
	 + "<b>(Link to Post)</b></a>";	*/
    return ss;

}

QString FacebookPostWidget::prepareStatus( const QString &txt ) 
{
	FacebookPost* post = static_cast<FacebookPost*>(currentPost());
	
	QString content = Choqok::UI::PostWidget::prepareStatus(post->content); 
	QString title = Choqok::UI::PostWidget::prepareStatus(post->title);
	QString caption = Choqok::UI::PostWidget::prepareStatus(post->caption);
	QString description = Choqok::UI::PostWidget::prepareStatus(post->description);
	QString story = Choqok::UI::PostWidget::prepareStatus(post->story);
	QString link = Choqok::UI::PostWidget::prepareStatus(post->link);
	QString status = story + " <br/> " +  prepareLink(link, title, caption, description) + "<br/> <br/>" + content;
   //QString status = Choqok::UI::PostWidget::prepareStatus(txt);
   
   return txt;
}

QString FacebookPostWidget::prepareLink(QString& link, QString& title, QString& caption, QString& description) const
{
	QString linkHtml = "<a href = \"" + link + "\"> <b> " + title + " </b><br/> " + caption + "</a><br/> " + description;   
	return linkHtml;
}
