.PHONY: clean All

All:
	@echo "----------Building project:[ Pokemon_From_File - Debug ]----------"
	@cd "Pokemon_From_File" && "$(MAKE)" -f  "Pokemon_From_File.mk"
clean:
	@echo "----------Cleaning project:[ Pokemon_From_File - Debug ]----------"
	@cd "Pokemon_From_File" && "$(MAKE)" -f  "Pokemon_From_File.mk" clean
