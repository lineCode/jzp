void startJzp(const std::string& IMAGE_FILENAME, const std::string& DATA_FILENAME) {

	constexpr uint_fast16_t MAX_FILE_SIZE = 9797;
	constexpr uint_fast8_t MIN_IMAGE_SIZE = 134;

	const size_t 
		TMP_DATA_FILE_SIZE = std::filesystem::file_size(DATA_FILENAME),
		TMP_IMAGE_FILE_SIZE = std::filesystem::file_size(IMAGE_FILENAME);

	if (TMP_DATA_FILE_SIZE > MAX_FILE_SIZE || MIN_IMAGE_SIZE > TMP_IMAGE_FILE_SIZE) {		
		std::cerr << "\nFile Size Error: " 
			<< (MIN_IMAGE_SIZE > TMP_IMAGE_FILE_SIZE
        			? "Image is too small to be a valid JPG image"
	        		: "Data file exceeds the maximum limit of " + std::to_string(MAX_FILE_SIZE)
			+ ".\n\n");

    		std::exit(EXIT_FAILURE);
	}
	
	std::ifstream
		image_file_ifs(IMAGE_FILENAME, std::ios::binary),
		data_file_ifs(DATA_FILENAME, std::ios::binary);

	if (!image_file_ifs || !data_file_ifs) {
		std::cerr << "\nRead File Error: Unable to read " << (!image_file_ifs 
			? "image file" 
			: "data file") 
		<< ".\n\n";

		std::exit(EXIT_FAILURE);
	}
	
	std::vector<uint_fast8_t>Profile_Vec = {
		0xFF, 0xD8, 0xFF, 0xE0, 0x00, 0x10, 0x4A, 0x46, 0x49, 0x46, 0x00, 0x01, 0x01, 0x00, 0x00, 0x01,
		0x00, 0x01, 0x00, 0x00, 0xFF, 0xE2, 0x0E, 0x8C, 0x49, 0x43, 0x43, 0x5F, 0x50, 0x52, 0x4F, 0x46,
		0x49, 0x4C, 0x45, 0x00, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x6c, 0x63, 0x6d, 0x73, 0x02, 0x10,
		0x00, 0x00, 0x6D, 0x6E, 0x74, 0x72, 0x52, 0x47, 0x42, 0x20, 0x58, 0x59, 0x5A, 0x20, 0x07, 0xE2,
		0x00, 0x03, 0x00, 0x14, 0x00, 0x09, 0x00, 0x0E, 0x00, 0x1D, 0x61, 0x63, 0x73, 0x70, 0x4D, 0x53,
		0x46, 0x54, 0x00, 0x00, 0x00, 0x00, 0x73, 0x61, 0x77, 0x73, 0x63, 0x74, 0x72, 0x6C, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF6, 0xD6, 0x00, 0x01,
		0x00, 0x00, 0x00, 0x00, 0xD3, 0x2D, 0x68, 0x61, 0x6E, 0x64, 0xEB, 0x77, 0x1F, 0x3C, 0xAA, 0x53,
		0x51, 0x02, 0xE9, 0x3E, 0x28, 0x6C, 0x91, 0x46, 0xAE, 0x57, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x09, 0x64, 0x65, 0x73, 0x63, 0x00, 0x00,
		0x00, 0xF0, 0x00, 0x00, 0x00, 0x1C, 0x77, 0x74, 0x70, 0x74, 0x00, 0x00, 0x01, 0x0C, 0x00, 0x00,
		0x00, 0x14, 0x72, 0x58, 0x59, 0x5A, 0x00, 0x00, 0x01, 0x20, 0x00, 0x00, 0x00, 0x14, 0x67, 0x58,
		0x59, 0x5A, 0x00, 0x00, 0x01, 0x34, 0x00, 0x00, 0x00, 0x14, 0x62, 0x58, 0x59, 0x5A, 0x00, 0x00,
		0x01, 0x48, 0x00, 0x00, 0x00, 0x14, 0x72, 0x54, 0x52, 0x43, 0x00, 0x00, 0x01, 0x5C, 0x00, 0x00,
		0x00, 0x34, 0x67, 0x54, 0x52, 0x43, 0x00, 0x00, 0x01, 0x5C, 0x00, 0x00, 0x00, 0x34, 0x62, 0x54,
		0x52, 0x43, 0x00, 0x00, 0x01, 0x5C, 0x00, 0x00, 0x00, 0x34, 0x63, 0x70, 0x72, 0x74, 0x00, 0x00,
		0x01, 0x90, 0x00, 0x00, 0x00, 0x01, 0x64, 0x65, 0x73, 0x63, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x05, 0x6E, 0x52, 0x47, 0x42, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x58, 0x59, 0x5A, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF3, 0x54, 0x00, 0x01,
		0x00, 0x00, 0x00, 0x01, 0x16, 0xC9, 0x58, 0x59, 0x5A, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x6F, 0xA0, 0x00, 0x00, 0x38, 0xF2, 0x00, 0x00, 0x03, 0x8F, 0x58, 0x59, 0x5A, 0x20, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x62, 0x96, 0x00, 0x00, 0xB7, 0x89, 0x00, 0x00, 0x18, 0xDA, 0x58, 0x59,
		0x5A, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x24, 0xA0, 0x00, 0x00, 0x0F, 0x85, 0x00, 0x00,
		0xB6, 0xC4, 0x63, 0x75, 0x72, 0x76, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x14, 0x00, 0x00,
		0x01, 0x07, 0x02, 0xB5, 0x05, 0x6B, 0x09, 0x36, 0x0E, 0x50, 0x14, 0xB1, 0x1C, 0x80, 0x25, 0xC8,
		0x30, 0xA1, 0x3D, 0x19, 0x4B, 0x40, 0x5B, 0x27, 0x6C, 0xDB, 0x80, 0x6B, 0x95, 0xE3, 0xAD, 0x50,
		0xC6, 0xC2, 0xE2, 0x31, 0xFF, 0xFF, 0x20, 0x6A, 0x7A, 0x70, 0x20
	},
		Image_Vec((std::istreambuf_iterator<char>(image_file_ifs)), std::istreambuf_iterator<char>());
	
	constexpr uint_fast8_t
		JPG_SIG[] 	{ 0xFF, 0xD8, 0xFF },
		JPG_END_SIG[] 	{ 0xFF, 0xD9 },
		DQT_SIG[]  	{ 0xFF, 0xDB },
		ZIP_SIG[] 	{ 0x50, 0x4B, 0x03, 0x04 },
		EXIF_SIG[] 	{ 0x45, 0x78, 0x69, 0x66, 0x00, 0x00, 0x49, 0x49 },
		XPACKET_SIG[] 	{ 0x78, 0x70, 0x61, 0x63, 0x6B, 0x65, 0x74, 0x20, 0x65, 0x6E, 0x64 },
		ICC_PROFILE_SIG[] { 0x49, 0x43, 0x43, 0x5F, 0x50, 0x52, 0x4F, 0x46, 0x49, 0x4C, 0x45 };

	if (!std::equal(std::begin(JPG_SIG), std::end(JPG_SIG), std::begin(Image_Vec)) 
		|| !std::equal(std::begin(JPG_END_SIG), std::end(JPG_END_SIG), std::end(Image_Vec) - 2)) {
        		std::cerr << "\nImage File Error: This is not a valid JPG image.\n\n";
			std::exit(EXIT_FAILURE);
    	}
		
	Profile_Vec.insert(Profile_Vec.end(), std::istreambuf_iterator<char>(data_file_ifs), std::istreambuf_iterator<char>());

	const uint_fast32_t ICC_PROFILE_POS = searchFunc(Image_Vec, 0, 0, ICC_PROFILE_SIG);
	if (Image_Vec.size() > ICC_PROFILE_POS) {
		Image_Vec.erase(Image_Vec.begin(), Image_Vec.begin() + ICC_PROFILE_POS);
	}

	const uint_fast32_t XPACKET_SIG_POS = searchFunc(Image_Vec, 0, 0, XPACKET_SIG);
	if (Image_Vec.size() > XPACKET_SIG_POS) {
		Image_Vec.erase(Image_Vec.begin(), Image_Vec.begin() + (XPACKET_SIG_POS + 0x11));
	}

	const uint_fast32_t EXIF_POS = searchFunc(Image_Vec, 0, 0, EXIF_SIG);
	if (Image_Vec.size() > EXIF_POS) {
		const uint_fast16_t EXIF_BLOCK_SIZE = (static_cast<uint_fast16_t>(Image_Vec[EXIF_POS - 2]) << 8) | static_cast<uint_fast16_t>(Image_Vec[EXIF_POS - 1]);
		Image_Vec.erase(Image_Vec.begin(), Image_Vec.begin() + EXIF_BLOCK_SIZE - 2);
	}

	const uint_fast32_t DQT_POS = searchFunc(Image_Vec, 0, 0, DQT_SIG);

	Image_Vec.erase(Image_Vec.begin(), Image_Vec.begin() + DQT_POS);
	
	uint_fast8_t
		bits = 16,				
		profile_header_size_index = 22,		
		profile_main_size_index = 38;	

	const uint_fast32_t VECTOR_SIZE = static_cast<uint_fast32_t>(Profile_Vec.size() - profile_header_size_index);	

	valueUpdater(Profile_Vec, profile_header_size_index, VECTOR_SIZE, bits, true);

	bits = 32; 

	valueUpdater(Profile_Vec, profile_main_size_index, VECTOR_SIZE - 16, bits, true);

	const uint_fast32_t DATA_FILE_INDEX = 443;

	if (std::equal(std::begin(ZIP_SIG), std::end(ZIP_SIG), std::begin(Profile_Vec) + DATA_FILE_INDEX))  {
        	adjustZipOffsets(Profile_Vec);
    	}
				 
	Image_Vec.insert(Image_Vec.begin(), Profile_Vec.begin(), Profile_Vec.end());
	
	const uint_fast32_t EMBEDDED_IMAGE_SIZE = static_cast<uint_fast32_t>(Image_Vec.size());
				   
	const std::string EMBEDDED_IMAGE_NAME = "jzp_img.jpg";

	std::ofstream file_ofs(EMBEDDED_IMAGE_NAME, std::ios::binary);

	if (!file_ofs) {
		std::cerr << "\nWrite Error: Unable to write to file.\n\n";
		std::exit(EXIT_FAILURE);
	}

	file_ofs.write((char*)&Image_Vec[0], EMBEDDED_IMAGE_SIZE);
				 
	std::cout << "\nCreated output file: \"" + EMBEDDED_IMAGE_NAME + " " << EMBEDDED_IMAGE_SIZE << " Bytes\"\n\n"
		<< "You can now post this data-embedded image file on X/Twitter.\n\n";
}
