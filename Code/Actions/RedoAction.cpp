#include "RedoAction.h"
#include "..\ApplicationManager.h"
#include "UndoAction.h"
#include <iostream>
using namespace std;
RedoAction::RedoAction(ApplicationManager* pApp) :Action(pApp)
{}

void RedoAction::Execute()
{
	count = pManager->getActioncount();
	cout << count << endl;
	if (count <= 5) {
		pManager->redoAction(count);
	
		pManager->setActioncount(count + 1);
		cout << count << endl;
	}
}

