template <class y>
class list{
	private:
		y* items;
		long count=0;
	public:
		list(){
			items=new y[0];
		}
		void resize(long c){
			count=c;
			items=(y*)realloc(items,sizeof(y)*count);
		}
		long size(){
			return count;
		}
		y& operator [](long index){
			if(index>=count){
				count=index+1;
				items=(y*)realloc(items,sizeof(y)*count);
			}
			return items[index];
		}
		void append(y item){
			count=count+1;
			items=(y*)realloc(items,sizeof(y)*count);
			items[count-1]=item;			
		}
		void append(list l){
			long lc=l.size();
			if(lc>0){
				long c;
				c=count;
				resize(count+lc);
				for(long i=0;i<lc;i++){
					items[c+i]=l[i];
				}
			}
		}
		list copy(long i1,long i2){
			list l;
			if(i1>=0 && i1<count && i2>=0 && i2<count){
				long i,c;
				if(i1<=i2){
					c=i2-i1+1;
					l.resize(c);
					for(i=0;i<c;i++){
						l[i]=items[i1+i];
					}
				}else{
					c=i1-i2+1;
					l.resize(c);
					for(i=0;i<c;i++){
						l[i]=items[i];
					}
				}	
			}
			return l;
		}
		list copy(long i1,long i2,bool isinstance){
			list l;
			if(i1>=0 && i1<count && i2>=0 && i2<count){
				long i,c,s;
				s=sizeof(y);
				if(i1<=i2){
					c=i2-i1+1;
					l.resize(c);
					if(isinstance){
						for(i=0;i<c;i++){
							l[i]=items[i1+i];
						}
					}else{
						memcpy((y*)l.items,(const y*)items+i1,s*c);
					}
				}else{
					c=i1-i2+1;
					l.resize(c);
					if(isinstance){
						for(i=0;i<c;i++){
							l[i]=items[i];
						}
					}else{
						memcpy((y*)l.items,(const y*)items+i2,s*c);	
					}
					
				}	
			}
			return l;
		}
		void remove(long index){
			if(index>=0 && index<count){
				if(count>1){
					y* _items=new y[count-1];
					long i;
					if(index==0){
						for(i=0;i<count-1;i++){
							_items[i]=items[i+1];
						}	
					}else if(index==count-1){
						for(i=0;i<count-1;i++){
							_items[i]=items[i];
						}
					}else{
						for(i=0;i<index;i++){
							_items[i]=items[i];
						}
						for(i=index+1;i<count-1;i++){
							_items[index+i]=items[i];
						}
					}
					count=count-1;
					delete []items;
					items=_items;
				}else{
					count=count-1;
					items=(y*)realloc(items,sizeof(y)*count);
				}
				
			}
		}
		~list(){
			delete []items;
		}
};
