void v_callback_w(void* widget,object block){
    //run the block
    //is the block's self set correctly?
    run(block,block);
	glstack.pop(); //discard return value
//    svmprint("\n");
}
object new_gdk_event(GdkEvent* x){
//do case on x->type = BIG_MACRO_EVENT_TYPE
//then do return new_object(all the stuff)
	object temp;
	
	switch(x->type){
	case GDK_KEY_PRESS:
		//newint_nodeclr(temp);
		//temp->value.d= ((GdkEventKey*)(x))->keyval;
		
		
		temp=create_new_object("keyevent","object","code","n",((GdkEventKey*)(x))->keyval, \
												   "string","s",((GdkEventKey*)(x))->string, \
																					0);
		break;
	default:
		temp=refobj(void);
	}
	return temp;//GDK_KEY_PRESS string is "r" keyval is 114
}
void v_callback_w_1arg(void* widget,GdkEvent* arg1,object block){
    //run the block
    //is the block's self set correctly?
    
	//change this so it constructs an appropriate object and sends this instead of the address of it
	//maybe new function like:
	//construct_new_object("mynewobject",1,object_parentobject,"name1",val1,"name2",val2,0)
	//but this will look up the integer code for the names EVERY CALL...
	object ss[1];
	ss[0]=new_gdk_event(arg1);
	//newint_nodeclr(ss[0]);
//	ss[0]->value.d=arg1;
	new_runx_with(block,block,1,ss);
    glstack.pop(); //discard return value
//    svmprint("\n");



}




primitive(__gui_propset_value){
//obj ... name value
	size_t value;
	char*name;
	ARG	
	value=ARGVAL;
	
	GETARG
	
	name=CARGVAL;
	
	gtk_object_set(GTK_OBJECT(OBJVAL),name,value,NULL);
	glstack.push(OBJ);
}
primitive(__gui_propget){
//obj ... name
	
	char* name;
ARG
	newint(retval);
	GtkArg a[1];
	a[0].name=CARGVAL;

	gtk_object_getv(GTK_OBJECT(OBJVAL),1,a);
	retval->value.d=GTK_VALUE_ULONG(a[0]);
	glstack.push(retval);

	
}

primitive(__gui_widget_new){
	ARG
	newint(temp);
	char*name=CARGVAL;
	temp->value.d=(size_t)(gtk_object_newv(gtk_type_from_name(name),0,NULL));
	glstack.push(temp);
}

primitive(enter_gui_loop){
    glstack.push(refobj(void));//have to push something or stack fscks up
    gtk_main();
}
primitive(exit_gui_loop){
    glstack.push(refobj(void));//every method must push something
    gtk_main_quit();
}

primitive(__signal_disconnect){
    object o=ocast(OBJ->gets(refmsg(forobj)));
  //  printf("zzz%s\n",o->name);
    gtk_signal_disconnect(GTK_OBJECT(o->value.d),OBJVAL);
    glstack.push(OBJ);
}

primitive(__signal_enable){
    object o=ocast(OBJ->gets(refmsg(forobj)));
    gtk_signal_handler_unblock(GTK_OBJECT(o->value.d),OBJVAL);
    glstack.push(OBJ);
}

primitive(__signal_disable){
    object o=ocast(OBJ->gets(refmsg(forobj)));
    gtk_signal_handler_block(GTK_OBJECT(o->value.d),OBJVAL);
    glstack.push(OBJ);
}

primitive(__signal_emit){
ARG
	gtk_signal_emit_by_name(GTK_OBJECT(OBJVAL),(char*)ARGVAL);
    glstack.push(OBJ);
}

primitive(__gui_signal_do){
ARG
    object temp;
	char* widget;
	void* block;
    block=glstack.pop();

    widget=CARGVAL;
    
    initobject(temp);
    temp->parent=refobj(signal);
    temp->isnamed=1;
    temp->name=(char*)CSasignal;

    temp->sets(refmsg(forobj),OBJ); 
    temp->value.d=gtk_signal_connect(GTK_OBJECT(OBJVAL),widget,GTK_SIGNAL_FUNC(v_callback_w),block);

    glstack.push(temp);

}
primitive(__gui_signal_do_with1arg){
//ARG
    object temp;
    char* widget;
	void* block;
	block=glstack.pop();
ARG
    widget=CARGVAL;
    
    initobject(temp);
    temp->parent=refobj(signal);
    temp->isnamed=1;
    temp->name=(char*)CSasignal;

    temp->sets(refmsg(forobj),OBJ); 
    temp->value.d=gtk_signal_connect(GTK_OBJECT(OBJVAL),(char*)widget,GTK_SIGNAL_FUNC(v_callback_w_1arg),block);

    glstack.push(temp);

}

primitive(__gui_container_add){
ARG
	gtk_container_add(GTK_CONTAINER(OBJVAL),(struct _GtkWidget *)(ARGVAL));
    glstack.push(OBJ);
}
primitive(__gui_widget_show){
    gtk_widget_show((struct _GtkWidget *)(OBJVAL));
    glstack.push(OBJ);
}
primitive(__gui_widget_hide){
    gtk_widget_hide((struct _GtkWidget *)(OBJVAL));
    glstack.push(OBJ);
}
primitive(__gui_widget_sizex_sizey){
    gtk_widget_set_usize((struct _GtkWidget *)(OBJVAL),ocast(glstack.pop())->value.d,ocast(glstack.pop())->value.d);
    glstack.push(refobj(void));
}

primitive(__gui_text_chars){
	newstring(temp);
	temp->value.d=(size_t)(gtk_editable_get_chars ((GtkEditable*)(OBJVAL),0,-1));
	glstack.push(temp);
}

primitive(__gui_ctree_insert_node){
ARG
	char* f[1];
	newint(temp);
	f[0]=CARGVAL;
	temp->value.d=(size_t)(gtk_ctree_insert_node(	(GtkCTree*)(OBJVAL),0,0,f,0,0,0,0,0,0,0));
	glstack.push(temp);
}
primitive(__gui_ctree_insert_node_specific){
ARG
	char* f[1];
	size_t sib=ARGVAL;
	GETARG
	size_t par=ARGVAL;
	newint(temp);
	GETARG
	f[0]=CARGVAL;
	temp->value.d=(size_t)(gtk_ctree_insert_node(	(GtkCTree*)(OBJVAL),(GtkCTreeNode*)(par),(GtkCTreeNode*)(sib),f,0,0,0,0,0,0,0));
	glstack.push(temp);
}
primitive(__gui_ctree_setlinestyle){
ARG
	size_t aaa=ARGVAL;
		switch(aaa){
		case 0:
			gtk_ctree_set_line_style((GtkCTree*)(OBJVAL),(GtkCTreeLineStyle)(GTK_CTREE_LINES_NONE));
			break;
		case 1:
			gtk_ctree_set_line_style((GtkCTree*)(OBJVAL),(GtkCTreeLineStyle)(GTK_CTREE_LINES_SOLID));
			break;
		case 2:
			gtk_ctree_set_line_style((GtkCTree*)(OBJVAL),(GtkCTreeLineStyle)(GTK_CTREE_LINES_DOTTED));
			break;
		case 3:
			gtk_ctree_set_line_style((GtkCTree*)(OBJVAL),(GtkCTreeLineStyle)(GTK_CTREE_LINES_TABBED));
			break;
	}
	glstack.push(OBJ);
}
primitive(__gui_ctree_setexpanderstyle){
ARG
	size_t aaa=ARGVAL;
		switch(aaa){
		case 0:
			gtk_ctree_set_expander_style((GtkCTree*)(OBJVAL),(GtkCTreeExpanderStyle)(GTK_CTREE_EXPANDER_NONE));
			break;
		case 1:
			gtk_ctree_set_expander_style((GtkCTree*)(OBJVAL),(GtkCTreeExpanderStyle)(GTK_CTREE_EXPANDER_SQUARE));
			break;
		case 2:
			gtk_ctree_set_expander_style((GtkCTree*)(OBJVAL),(GtkCTreeExpanderStyle)(GTK_CTREE_EXPANDER_TRIANGLE));
			break;
		case 3:
			gtk_ctree_set_expander_style((GtkCTree*)(OBJVAL),(GtkCTreeExpanderStyle)(GTK_CTREE_EXPANDER_CIRCULAR));
			break;
	}
	glstack.push(OBJ);
	
}

primitive(__gui_ctree_setindent){
ARG
	gtk_ctree_set_indent((GtkCTree*)(OBJVAL),ARGVAL);
	gtk_ctree_set_show_stub   ((GtkCTree*)(OBJVAL),100);      
	gtk_ctree_set_spacing ((GtkCTree*)(OBJVAL),200);          
	glstack.push(OBJ);
}
