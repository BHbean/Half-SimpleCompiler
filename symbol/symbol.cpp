#include "./symbol.h"
#include "../tree/IdDeclarationNode.h"
#include "../tree/OperatorNode.h"
#include <string>

Symbol::Symbol() {

	this->name = "None";
	this->type = SymbolType::none;
}

Symbol::Symbol(std::string name, SymbolType type) {
	this->name = name;
	this->type = type;
}

std::string Symbol::getname() {
	return this->name;
}

SymbolType &Symbol::gettype() {
	return this->type;
}

// std::string Symbol::gettypeString(){
// 	return std::to_string((int)this->type);
// }

void Symbol::change(std::string name, SymbolType type) {
	this->name = name;
	this->type = type;
}

SymbolTable::SymbolTable() {
	this->parentTable = NULL;
	this->childTable = new std::vector<SymbolTable*>();
	// this->symbolItemCount = 0;
	// this->totalOffset = 4;
}


void SymbolTable::addChild(SymbolTable * node)
{
	if (NULL != node) {
		this->childTable->push_back(node);
		//node->setParent(this);
		/*SymbolTable * tmp = node->getRightSibling();
		std::cout << node->getRightSibling() << std::endl;
		while (NULL != tmp) {
			this->child->push_back(tmp);
			tmp->setParent(this);
			tmp = tmp->getRightSibling();
		}*/
	}
}

int SymbolTable::addSymbol(Symbol *symbol) {
	if (this->IfInThisTable(symbol->getname()) == false) {
		this->SymbolHashtable.insert({ symbol->getname(),symbol });
		this->baseTable->test();
		//this->baseTable->push_array(symbol);
		// this->baseTable->setsymbolItemCount(this->baseTable->getsymbolItemCount()+1);
		// symbol->setOffset(this->baseTable->getTotalOffset());
		// if(symbol->getType() == SymbolType::integer || symbol->getType() == SymbolType::pointer){
		// 	this->baseTable->settotalOffset(this->baseTable->getTotalOffset() + INT_OFFSET);
		// }
		return true;
	}
	else {
		return false;
	}

}

int SymbolTable::addArraySymbol(std::string name, int flag) { 
	// std::vector<ASTNode*>* test_vec = decArray->getChild();
	// auto tmp_1 = (*test_vec).begin();
	// IdDeclarationNode * tmp_2 = dynamic_cast<IdDeclarationNode*>(*tmp_1);
	// std::string name = tmp_2->getIdentifier();	
	if (this->IfInThisTable(name) == false) {
		Symbol * s = new Symbol(name, SymbolType::array);
		this->baseTable->symbolArray->push_back(s);
		s->setIndex(this->baseTable->symbolItemCount++);
		s->setOffset(this->baseTable->totalOffset);
		this->baseTable->totalOffset += flag * 4;
		this->SymbolHashtable[name] = s;
		return true;
	}
	else {
		return false;
	}
}

void SymbolTable::delSymbol(Symbol *symbol) {
	this->SymbolHashtable.erase(symbol->getname());
}

int SymbolTable::changeSymbol(Symbol *symbol) {
	if (this->IfInThisTable(symbol->getname()) == true) {
		this->SymbolHashtable[symbol->getname()] = symbol;
		return true;
	}
	else {
		if (this->parentTable == NULL) {
			/*没有造成修改*/
			return false;
		}
		else {
			this->parentTable->changeSymbol(symbol);
			return true;
		}
	}
	
}

/*Symbol* SymbolTable::searchSymbol(Symbol *symbol) {
	if (this->IfInThisTable(symbol->getname()) == true) {
		return this->SymbolHashtable[symbol->getname()];
	}
	else {
		if (this->parentTable == NULL) {
			Symbol *symbol = new Symbol();
			return symbol;
		}
		else {
			this->parentTable->searchSymbol(symbol);
		}
	}
	
}*/

Symbol* SymbolTable::searchSymbol(std::string symbol_name) {
	if (this->IfInThisTable(symbol_name) == true) {
		return this->SymbolHashtable[symbol_name];
	}
	else {
		if (this->parentTable == NULL) {
			Symbol *symbol = new Symbol();
			return symbol;
		}
		else {
			this->parentTable->searchSymbol(symbol_name);
		}
	}
	
}

int SymbolTable::IfInThisTable(std::string name) {
	std::unordered_map<std::string, Symbol*>::iterator iter;
	for (iter = this->SymbolHashtable.begin(); iter != this->SymbolHashtable.end(); iter++) {
		if (iter->first == name) {
			return true;
		}
	}
	return false;
}

void SymbolTable::printSymbol() {
	std::unordered_map<std::string, Symbol*>::iterator iter;
	for (iter = this->SymbolHashtable.begin(); iter != this->SymbolHashtable.end(); iter++) {
		std::cout << iter->first << "  " << (int)iter->second->gettype() << std::endl;
	}

}
