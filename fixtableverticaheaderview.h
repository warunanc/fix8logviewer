/*
Fix8logviewer is released under the GNU LESSER GENERAL PUBLIC LICENSE Version 3.

Fix8logviewer Open Source FIX Log Viewer.
Copyright (C) 2010-14 David N Boosalis dboosalis@fix8.org, David L. Dight <fix@fix8.org>

Fix8logviewer is free software: you can  redistribute it and / or modify  it under the  terms of the
GNU Lesser General  Public License as  published  by the Free  Software Foundation,  either
version 3 of the License, or (at your option) any later version.

Fix8logviewer is distributed in the hope  that it will be useful, but WITHOUT ANY WARRANTY;  without
even the  implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

You should  have received a copy of the GNU Lesser General Public  License along with Fix8.
If not, see <http://www.gnu.org/licenses/>.

BECAUSE THE PROGRAM IS  LICENSED FREE OF  CHARGE, THERE IS NO  WARRANTY FOR THE PROGRAM, TO
THE EXTENT  PERMITTED  BY  APPLICABLE  LAW.  EXCEPT WHEN  OTHERWISE  STATED IN  WRITING THE
COPYRIGHT HOLDERS AND/OR OTHER PARTIES  PROVIDE THE PROGRAM "AS IS" WITHOUT WARRANTY OF ANY
KIND,  EITHER EXPRESSED   OR   IMPLIED,  INCLUDING,  BUT   NOT  LIMITED   TO,  THE  IMPLIED
WARRANTIES  OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  THE ENTIRE RISK AS TO
THE QUALITY AND PERFORMANCE OF THE PROGRAM IS WITH YOU. SHOULD THE PROGRAM PROVE DEFECTIVE,
YOU ASSUME THE COST OF ALL NECESSARY SERVICING, REPAIR OR CORRECTION.

IN NO EVENT UNLESS REQUIRED  BY APPLICABLE LAW  OR AGREED TO IN  WRITING WILL ANY COPYRIGHT
HOLDER, OR  ANY OTHER PARTY  WHO MAY MODIFY  AND/OR REDISTRIBUTE  THE PROGRAM AS  PERMITTED
ABOVE,  BE  LIABLE  TO  YOU  FOR  DAMAGES,  INCLUDING  ANY  GENERAL, SPECIAL, INCIDENTAL OR
CONSEQUENTIAL DAMAGES ARISING OUT OF THE USE OR INABILITY TO USE THE PROGRAM (INCLUDING BUT
NOT LIMITED TO LOSS OF DATA OR DATA BEING RENDERED INACCURATE OR LOSSES SUSTAINED BY YOU OR
THIRD PARTIES OR A FAILURE OF THE PROGRAM TO OPERATE WITH ANY OTHER PROGRAMS), EVEN IF SUCH
HOLDER OR OTHER PARTY HAS BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.

*/
#ifndef FIXTABLEVERTICAHEADERVIEW_H
#define FIXTABLEVERTICAHEADERVIEW_H

#include <QHeaderView>
#include <QList>
#include <QStandardItem>
class WorkSheetModel;
class ProxyFilter;

class FixTableVerticaHeaderView : public QHeaderView
{
public:
    explicit FixTableVerticaHeaderView(QWidget *parent = 0);
    void setHighlightList(QVector <qint32>,QList <QStandardItem *> *items,bool turnOn=true);
    void turnOnSearchHighLight(bool on);
    void redoSearch();
    void setProxyFilter(ProxyFilter *);
    void setProxyFilterOn(bool);
    void setWorkModel(WorkSheetModel *m);
protected:
    //void mousePressEvent(QMouseEvent *e);
   //void  computerActualHighLightedRows();
   virtual void  paintSection(QPainter *painter,const QRect &,int logicalIndex) const;
   QVector <qint32> actualHightlightRows;
   QVector <qint32> hightlightRows;
    QList <QStandardItem *> *hightLightItems;
    QList <QStandardItem *>  proxyhightLightItems;

   bool highLightOn;
   ProxyFilter *proxyFilter;
   WorkSheetModel *_model;
   bool proxyFilterOn;
};

#endif // FIXTABLEVERTICAHEADERVIEW_H
