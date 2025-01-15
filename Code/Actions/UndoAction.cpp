#include "UndoAction.h"
#include "..\ApplicationManager.h"
#include <iostream>
using namespace std;
UndoAction::UndoAction(ApplicationManager* pApp) :Action(pApp)
{}

void UndoAction::Execute() {
	count = pManager->getActioncount();
	cout << count << endl;
	if (count > 0) {
		pManager->undoAction(count);
		pManager->setActioncount(count - 1);
		cout << count << endl;
	}
}
