
// MODIFY MACOS AS PER YOUR DATASET
#define CLAUSES 200
#define CLASSES 2
#define NUMBER_OF_EXAMPLES_TRAIN 8012
#define NUMBER_OF_EXAMPLES_TEST 1002
#define THRESHOLD 10
#define FEATURES 8820 

#define NUMBER_OF_STATES 200
#define BOOST_TRUE_POSITIVE_FEEDBACK 0

#define PREDICT 1
#define UPDATE 0


//Ctypes
#ifdef __cplusplus
extern "C" {
#endif

// declarations

#ifdef __cplusplus
}
#endif



struct TsetlinMachine { 
	short ta_state[CLAUSES][FEATURES][2];

	int clause_output[CLAUSES];

	int hit_count;

	int num_samples;

	int feedback_to_clauses[CLAUSES];
};

struct TsetlinMachine *CreateTsetlinMachine();

void tm_initialize(struct TsetlinMachine *tm);

unsigned int tm_show_value(struct TsetlinMachine *tm, int class_number);

void tm_update(struct TsetlinMachine *tm, int Xi[], int target, float s);

int tm_score(struct TsetlinMachine *tm, int Xi[]);

int tm_get_state(struct TsetlinMachine *tm, int clause, int feature, int automaton_type);

int tm_save(struct TsetlinMachine *tm, const char *filename);

struct TsetlinMachine *tm_load(const char *filename);


