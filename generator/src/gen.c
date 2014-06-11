#include <string.h>
#include <jansson.h>

#define ERR(fmt, ...) printf("Error: " fmt "\n", ##__VA_ARGS__)

int main(int argc, char *argv[])
{
	// TODO: parse options
	// TODO: foreach fact
	const char *facts_path = "../facts/facts.json";
	json_error_t error;
	json_t *facts_json = json_load_file(facts_path, 0, &error);
	if (facts_json == NULL) {
		ERR("Failed to decode facts json, %s", error.text);
		exit(2);
	}

	printf("dumped json: \n %s", json_dumps(facts_json, 0));

	return 0;
}
