/****************************************************************************
**
** Trolltech hereby grants a license to use the Qt/Eclipse Integration
** plug-in (the software contained herein), in binary form, solely for the
** purpose of creating code to be used with Trolltech's Qt software.
**
** Qt Designer is licensed under the terms of the GNU General Public
** License versions 2.0 and 3.0 ("GPL License"). Trolltech offers users the
** right to use certain no GPL licensed software under the terms of its GPL
** Exception version 1.2 (http://trolltech.com/products/qt/gplexception).
**
** THIS SOFTWARE IS PROVIDED BY TROLLTECH AND ITS CONTRIBUTORS (IF ANY) "AS
** IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED
** TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
** PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER
** OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
** EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
** PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
** PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
** LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
** NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
** SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** Since we now have the GPL exception I think that the "special exception
** is no longer needed. The license text proposed above (other than the
** special exception portion of it) is the BSD license and we have added
** the BSD license as a permissible license under the exception.
**
****************************************************************************/
#include <QMessageBox>
#include "MobileIM.h"
#include "chat.h"
MobileIM::MobileIM(QWidget *parent)
    : QWidget(parent)
{
	ui.setupUi(this);
	m_myname = new QListWidgetItem("My Name");
	m_memberlist.append(m_myname);
	ui.listWidget->addItem(m_myname);
	m_clickedtime = 0;
	m_tabindex = 0;
//	m_chatingflag = false;
	chatwindow = new Chat;
	QObject::connect(ui.tballcontacts, SIGNAL(clicked()),
					 this, SLOT(spreadMemberList()));
	QObject::connect(ui.pbmenu, SIGNAL(clicked()),
					 this, SLOT(addMember()));


	QObject::connect(ui.listWidget,SIGNAL(itemDoubleClicked(QListWidgetItem*)),
					 this,SLOT(goToChat(QListWidgetItem*)));
}

MobileIM::~MobileIM()
{
	delete m_myname;
	QObject::disconnect(ui.tballcontacts, SIGNAL(clicked()),
					 this, SLOT(spreaMemberdList()));
	QObject::disconnect(ui.pbmenu, SIGNAL(clicked()),
					 this, SLOT(addMember()));
}
void MobileIM::addMember()
	{

	QListWidgetItem *newitem1 = new QListWidgetItem("Myfriend1");
	QListWidgetItem *newitem2 = new QListWidgetItem("Myfriend2");
	m_memberlist.append(newitem1);
	m_memberlist.append(newitem2);
	for(int i = 1;i < m_memberlist.size();i++)
		{
		ui.listWidget->addItem(m_memberlist.at(i));
		}
		
	}
void MobileIM::spreadMemberList()
	{
	m_clickedtime++;
	
	if (0 == m_clickedtime % 2)
		{
		ui.tballcontacts->setArrowType(Qt::DownArrow);

		if(!m_memberlist.isEmpty())
			{
			for(int i=0;i<m_memberlist.size();i++)
				{
				m_memberlist.at(i)->setHidden(false);
				}
			}
		else
			{
			QMessageBox *msgbox = new QMessageBox(this);
			msgbox->setText("please select one file!");
			msgbox->show();
			}

		}
	else
		{
		ui.tballcontacts->setArrowType(Qt::RightArrow);

		if(!m_memberlist.isEmpty())
			{
			for(int i=0;i<m_memberlist.size();i++)
				{
				m_memberlist.at(i)->setHidden(true);
				}
			}
		else
			{
			QMessageBox *msgbox = new QMessageBox(this);
			msgbox->setText("please select one file!");
			msgbox->show();
			}

		}	
	}
void MobileIM::goToChat(QListWidgetItem *item)
	{
	chatwindow->draw(item);
			
	}






