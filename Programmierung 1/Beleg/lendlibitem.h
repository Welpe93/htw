/**
 * @defgroup LendLibItem
 * @brief Funktionen und Deklarationen rund um ausgeliehene Medien.
 * @{
 */

/**
 * @brief Typ des ausgeliehenen Mediums.
 */
typedef enum{
	other,	///< Medium ohne Kategorie
	book,	///< Bücher
	cd,		///< CDs
	dvd		///< DVDs
} mType;

/**
 * @brief Möglichkeiten, nach denen Sortiert/gesucht werden kann
 */
typedef enum{
	title,	///< Nach Medientitel
	lendee,	///< Nach Leihendem
	id		///< Nach ID
} sBy;

/**
 * @brief Das ausgeliehene Medium.
 */
typedef struct{
	int id;
	mType	type;		///< Typ des ausgeliehen Mediums
	char*	title;		///< Titel des Mediums
	char*	author;		///< Autor bzw. Interpret des Mediums
	char*	lendee;		///< Name der Person, dem das Medium verliehen wurde
} medium;

/**
 * @brief Eintrag in der Liste der verliehenen Medien
 */
typedef struct LITEM{
	struct LITEM* next;	///< Zeigt auf vorhergehenden Eintrag
	struct LITEM* prev;	///< Zeigt auf folgenden Eintrag
	medium *item;		///< Inhalt
}lItem;

/**
 * @brief Verwaltet die Liste der verliehenen Medien
 */
typedef struct{
	lItem* first;		///< Erster Eintrag
	lItem* curr;		///< aktueller Eintrag
	unsigned int size;	///< größe der Liste
	unsigned int sort;	///< Liste ist sortiert nach 0: Titel, 1:Ausleihenden
}theLib;

theLib *currLib;
theLib myLib;
lItem *myItems;
medium *myMedia;
int myItemsCount;
int myMediaCount;
unsigned int idc;

void initLib();
char* getmType(int type);
medium* createItem(int ntype, char* ntitle, char* nauthor, char* nlendee);
medium* createItemF(FILE *libitem);
void insertItem(medium *nMedium, theLib *inLib);
void deleteItem(int theID, theLib *inLib);
void sortItems(sBy sortBy, theLib *inLib);
void findItem(char *sItem, sBy findBy, theLib *inLib);
void freeAll(theLib *inLib);
int strcicmp(char const *a, char const *b);
/// @}