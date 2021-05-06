.PHONY: clean All

All:
	@echo "----------Building project:[ A11_Hash_Tables - Debug ]----------"
	@cd "A11_Hash_Tables" && "$(MAKE)" -f  "A11_Hash_Tables.mk"
clean:
	@echo "----------Cleaning project:[ A11_Hash_Tables - Debug ]----------"
	@cd "A11_Hash_Tables" && "$(MAKE)" -f  "A11_Hash_Tables.mk" clean
