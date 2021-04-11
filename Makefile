.PHONY: clean All

All:
	@echo "----------Building project:[ z_testing_alex_a10 - Debug ]----------"
	@cd "z_testing_alex_a10" && "$(MAKE)" -f  "z_testing_alex_a10.mk"
clean:
	@echo "----------Cleaning project:[ z_testing_alex_a10 - Debug ]----------"
	@cd "z_testing_alex_a10" && "$(MAKE)" -f  "z_testing_alex_a10.mk" clean
